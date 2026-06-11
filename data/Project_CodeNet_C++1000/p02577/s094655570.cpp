/************************************
/ AUTHOR : YATHARTH GOSWAMI         /  
/ ALIAS : hacker_yg                 /
/ INSTITUTE : IIT Kanpur            /
************************************/
//          TEMPLATE                //

#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265359

using namespace std;

/*ll powMod(ll a, ll y)
{
    ll ans = 1;
    
    while (y > 0) 
    { 
        if (y & 1) 
            ans = (ans*a) % MOD; 
  
        y = y>>1;
        a = (a*a) % MOD; 
    } 
    return ans;
}*/

/*ll modInv(ll a)
{
    return powMod(a, MOD-2);	
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    ll sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i]-'0';
    }
    if (sum%9==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}


