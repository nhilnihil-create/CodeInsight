#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int n;  cin >> n;
    map<ll, int> mp;
    for(int i=0; i<n; i++){
        ll x;   cin >> x;
        mp[x] += 1;
    }
    string ans="No";
    if(mp.size()<=3){
        if(mp.size()==1 && 0<mp[0]) ans="Yes";
        else if(n%3==0 && mp.size()==2){
            if(mp[0]==n/3) ans = "Yes";
        }else if(n%3==0 && mp.size()==3){
            ll p=0; bool flag=true;
            for(auto x: mp){
                p = p^x.first;
                if(x.second!=n/3) flag = false;
            }
            if(p==0 && flag) ans="Yes";
        }
    } 
    cout << ans << endl;
}