#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    int Mmin = N-1;
    int Mmax = (N-1)*(N-2)/2;
    if(K>Mmax){
        cout << -1 << endl;
        return 0;
    }
    
    int M = N*(N-1)/2 - K;
    cout << M << endl;
    int Mcnt = 0;
    for(int i = 1;i<N;++i)for(int j=i+1;j<=N;++j){
        cout << i << " " << j << endl;
        ++Mcnt;
        if(Mcnt == M) return 0;
    }
}