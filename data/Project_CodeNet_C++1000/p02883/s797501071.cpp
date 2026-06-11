#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long N, K;
    cin >> N >> K;

    long A[N], F[N];
    long sa = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        sa += A[i];
    }
    for(int i=0; i<N; i++){
        cin >> F[i];
    }
    if(sa <= K){
        cout << 0 << endl;
        return 0;
    }
    sort(A, A+N);
    sort(F, F+N, greater<int>());

    long l = -1;
    long r = 1000000000000000;
    long mid = (l+r)/2;
    while(r > l+1){
        mid = (l+r)/2;
        long ts = 0;
        for(int i=0; i<N; i++){
            ts += max(A[i]-mid/F[i], (long)0);
        }
        if(ts <= K) r = mid;
        else l = mid;
    }

    printf("%ld\n", l+1);

    return 0;
}