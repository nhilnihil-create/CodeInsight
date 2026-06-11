#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    ll A,B,K;
    cin >> A >> B >> K;
    if(A < K){
        K-=A;
        A=0;
        if(B<K) B = 0;
        else B-=K;
    }
    else A-=K;
    cout << A << " " << B << endl;
}