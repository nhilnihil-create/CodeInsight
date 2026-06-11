#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl = vector<ll>; using vvl = vector<vl>;
using vp = vector<pair<int,int>>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main() {
    int n,m;cin >> n >> m;
    vector<pair<int,string>> in(m);
    vector<bool> TF(n+1,false);
    rep(i,m){
        int a;string s;
        cin >> a >> s;
        pair<int,string> p;
        p.first = a;
        p.second = s;
        in[i]=p;
    }
    int wa = 0;
    int ac = 0;
    vector<int> numwa(n+1,0);
    rep(i,m){
        if(TF[in[i].first]) continue;
        if(in[i].second == "WA") numwa[in[i].first]++;
        if(in[i].second == "AC") {
            ac++;
            TF[in[i].first] = true;
            wa += numwa[in[i].first];
        }
    }
    cout << ac << " " << wa << endl;
}