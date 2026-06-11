#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll n = s.size();
    s.push_back('R');
    vector<ll> ans(n,0);
    ll start = 0;
    ll end = 0;
    ll top = 0;

    for (ll i = 0; i < n; i++){
        if (s[i] == 'L' && s[i+1] == 'R'){
            end = i+1;
            ll even = 0;
            ll odd = 0;
            if (start%2 == 0){
                if (end%2 == 0){
                    even = (end - start)/2;
                    odd = (end - start)/2;
                }
                else{
                    even = ((end - start)/2) +1;
                    odd = (end - start)/2;
                }
            }
            else {
                if (end%2 == 0){
                    even = (end - start)/2;
                    odd = ((end - start)/2) +1;
                }
                else{
                    even = (end - start)/2;
                    odd = (end - start)/2;
                }
            }

            for (ll j = start; j < end; j++){
                if (s[j] == 'R' && s[j+1] == 'L'){
                    if (j % 2 == 0){
                        ans[j] = even;
                        ans[j+1] = odd;
                    }
                    else{
                        ans[j] = odd;
                        ans[j+1] = even;
                    }
                    break;
                }
            }
            start = i+1;
        }
    }

    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
}