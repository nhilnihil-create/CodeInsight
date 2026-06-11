#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N+1,0);
    vector<long long> B(N, 0);

    for(int i=0; i<N+1; i++){
        cin >> A[i];
    }

    for(int i=0; i<N; i++){
        cin >> B[i];
    }

    long long count = 0;
    for(int i=0; i<N; i++){
        long long r = B[i] - A[i];
        if(r <= 0){
            count += B[i];
        }else{
            count += A[i];
            long long r2 = A[i+1] - r;
            if(r2 <= 0){
                count += A[i+1];
                A[i+1] = 0;
            }else{
                count += r;
                A[i+1] = r2;
            }
        }
    }
    cout << count << endl;
    return 0;

}