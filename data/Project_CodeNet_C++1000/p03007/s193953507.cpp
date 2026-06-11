#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    ll a[n];
    vector<ll> p;
    vector<ll> m;

    rep(i, 0, n){
        cin >> a[i];
        if(a[i] >= 0){
            p.push_back(a[i]);
        }else{
            m.push_back(a[i]);
        }
    }


    sort(p.begin(), p.end(), greater<ll>());
    sort(m.begin(), m.end());

    pair<ll, ll> ans[n - 1];
    rep(i, 0, n - 1){
        if(p.size() == 0){
            ans[i] = pair<ll, ll>(m[m.size() - 1], m[m.size() - 2]);
            p.push_back(m[m.size() - 1] - m[m.size() - 2]);
            m.pop_back();
            m.pop_back();
        }else if(m.size() == 0){
            ans[i] = pair<ll, ll>(p[p.size() - 1], p[p.size() - 2]);
            m.push_back(p[p.size() - 1] - p[p.size() - 2]);
            p.pop_back();
            p.pop_back();
        }else if(p.size() > m.size()){
            ans[i] = pair<ll, ll>(m[m.size() - 1], p[p.size() - 1]);
            m[m.size() - 1] = m[m.size() - 1] - p[p.size() - 1];
            p.pop_back();
        }else{
            ans[i] = pair<ll, ll>(p[p.size() - 1], m[m.size() - 1]);
            p[p.size() - 1] = p[p.size() - 1] - m[m.size() - 1];
            m.pop_back();
        }
    }

    cout << p[0] << endl;
    rep(i, 0, n - 1){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
