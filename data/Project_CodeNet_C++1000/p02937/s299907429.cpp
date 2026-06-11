#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

int main(){
    vector<ll> vec[26];
    string s,t;
    cin >> s >> t;
    rep(i,0,s.size()){
        vec[s[i] - 'a'].push_back(i);
    }

    ll cnt = 0,index = -1;
    rep(i,0,t.size()){
        ll temp = t[i] - 'a';
        if(vec[temp].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        else{
            ll ng = -1, ok = vec[temp].size();
            while(abs(ok-ng) > 1){
                ll mid = (ok+ng)/2;
                if(vec[temp][mid] > index){
                    ok = mid;
                }
                else{
                    ng = mid;
                }
            } 

            if(ok == vec[temp].size()){
                cnt++;
                index = vec[temp][0];
            }
            else{
                index = vec[temp][ok];
            }
        }
        //cout << cnt << " " << index << endl;
    }
    cout << cnt*s.size() + index + 1 << endl;
}


