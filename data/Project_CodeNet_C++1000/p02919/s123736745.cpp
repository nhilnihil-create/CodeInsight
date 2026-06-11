#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n; cin >> n;
    vector<P> d(n);
    rep(i,n){
        int p; cin >> p;
        d.emplace_back(p,i+1);
    }
    sort(all(d));
    reverse(all(d));
    
    multiset<int> left,right;
    ll ans=0;

    left.insert(0);
    left.insert(0);
    left.insert(-d[0].second);
    right.insert(d[0].second);
    right.insert(n+1);
    right.insert(n+1);

    for(int i=1; i<n; i++){
        ll now=d[i].first;
        int id=d[i].second;
        int l1=*left.lower_bound(-id);
        left.erase(left.find(l1));
        int l2=*left.lower_bound(-id);
        left.insert(l1);
        int r1=*right.lower_bound(id);
        right.erase(right.find(r1));
        int r2=*right.lower_bound(id);
        right.insert(r1);
        //cout << l1 << l2 << r1 << r2 << endl;
        l1*=-1;
        l2*=-1;
        ans+=now*((ll)(id-l1)*(r2-r1)+(ll)(r1-id)*(l1-l2));
        left.insert(-id);
        right.insert(id);
    }

    cout << ans << endl;
return 0;
}