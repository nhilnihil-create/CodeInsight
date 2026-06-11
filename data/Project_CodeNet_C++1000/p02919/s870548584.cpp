#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=1; i<=n; i++){
        int p;
        cin >> p;
        mp[p]=i;
    }
    set<int> se;
    ll ans=0ll;
    for(int i=n; i>=1; i--){
        int idx=mp[i];
        se.insert(idx);
        vector<int> l(2,0);
        vector<int> r(2,n+1);
        auto it=se.find(idx);
        rp(j,2){
            if(it==se.begin()) break;
            --it;
            l[1-j]=*it;
        }
        it=se.find(idx);
        rp(j,2){
            ++it;
            if(it==se.end()) break;
            r[j]=*it;
        }
        ll c=(l[1]-l[0])*(r[0]-idx)+(r[1]-r[0])*(idx-l[1]);
        ans += (ll)i*c;
    }
    cout << ans << endl;
    return 0;
}