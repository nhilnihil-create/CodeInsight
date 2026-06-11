#include <iostream>
#include <map>

using namespace std;
const long MOD = 1000000007;

int main(){
    int N;
    cin >> N; 

    int A[N];
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i] == 0) cnt++;
    }

    long ans = 1;
    int pre = 3;
    map<int, int> m;
    for(int i=0; i<N; i++){
        if(m.count(A[i]) == 0){
            m[A[i]] = 1;
        }else{
            m[A[i]]++;
        }
        if(A[i] != 0){
            ans = ans * m[A[i]-1] % MOD;
            m[A[i]-1]--;
        }
    }

    int s = 3;
    while(cnt != 0){
        ans = ans * s % MOD;
        cnt--;
        s--;
    }

    printf("%ld\n", ans);

    return 0;
}