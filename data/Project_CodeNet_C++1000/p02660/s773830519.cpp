/*
      author : Nishikawa
      created: 07.08.2020 17:54:25
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

class Sieve{
public:
    vector<pair<ll,int>> pf(ll n){
        vector<pair<ll,int>> res;
        for(ll i=2; i*i<=n; i++){
            int x=0;
            while(n%i==0){
                n/=i;
                ++x;
            }
            res.emplace_back(i,x);
        }
        if(n!=1) res.emplace_back(n,1);
        return res;
    }
};

int main(){
    ll n;
    cin >> n;
    Sieve s;
    int ans = 0;
    auto fs = s.pf(n);
    for(auto a : fs){
        int x = a.second;
        int b = 1;
        while(b <= x){
            x -= b;
            b++; 
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}