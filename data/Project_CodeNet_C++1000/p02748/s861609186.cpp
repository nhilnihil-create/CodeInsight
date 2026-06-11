#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pil = pair<pii,int>;

int main(){
    int s,t,m;
    cin >> s >> t >> m;
    vector<int> a(s);
    rep(i,s) cin >> a[i];
    vector<int> b(t);
    rep(i,t) cin >> b[i];
    int r = 2e9;
    rep(i,m){
        int x,y,z;
        cin >> x >> y >> z;
        int s = a[x-1] + b[y-1] - z;
        r = min(r,s);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    r = min(r,(a[0]+b[0]));
    cout << r << endl;
}
