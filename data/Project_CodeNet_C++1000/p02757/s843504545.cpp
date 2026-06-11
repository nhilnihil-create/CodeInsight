#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

#define ll long long int
#define mod 1000000007

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    unordered_map<ll, ll> um;
    
    if(p == 5 || p == 2){
        ll c = 0;
        for(ll i = n - 1; i >= 0; i--){
            if((s[i]-'0')% p == 0)
            c += i+1;
        }
        cout << c;
    }
    
    else{
    ll cnt = 0;
    ll t = 1;
    ll x = 0;
    for(ll i = n - 1; i >= 0; i--){
         x = (x + t*(s[i]- '0'))%p ;
        
        if(x % p == 0){
            cnt++;
        }
        um[x%p]++;
        
        t = (t * 10) % p ;
    }
    
    for(auto i : um){
        cnt += (i.second)*(i.second - 1)/2;
    }
    cout <<cnt;
    }
}







