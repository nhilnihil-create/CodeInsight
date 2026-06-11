#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(ll i=0;i<n;++i)

int main(void){
    int N;
    cin >> N;
    ll buf, res = 0;
    // x_i = x_{i+3}が常に成立
    REP(i,N){
        cin >> buf;
        res ^= buf;
    }
    if(res==0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}