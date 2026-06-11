#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mod = 1e9 + 7;
int main(){
    string l;
    cin >> l;
    int n = l.size();

    vector<ll> dp1(n, 0);
    vector<ll> dp2(n, 0);
    
    dp1[0] = 1;
    dp2[0] = 2;
    for(int i=1;i<n;i++){
        if(l[i] == '1'){
            dp1[i] = (dp1[i-1] * 3 + dp2[i-1])%mod;
            dp2[i] = (dp2[i-1] * 2)%mod;
        }else{
            dp1[i] = (dp1[i-1] * 3)%mod;
            dp2[i] = (dp2[i-1])%mod;
        }
    }
    

    cout << (dp1[n-1] + dp2[n-1])%mod << endl;

}