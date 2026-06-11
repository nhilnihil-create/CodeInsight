#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n; cin>>n;
    vector <int> a(n); 
    vector <int> b(n); 
    priority_queue <pair<int,int>> pq;
    rep(i,n) cin>>a[i];
    rep(i,n) {cin>>b[i]; pq.push({b[i], i});}
    int ans = 0;
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        int i = now.S;
        int mid = now.F, r = b[(i-1 <0) ? n-1: i-1], l = b[(i+1)%n];
        if(a[now.S] == mid) continue;
        if(mid < a[i]) {cout<<-1<<endl; return 0;}
        int k = (b[i]-a[i])/(r+l);
        if(k==0) {cout<<-1<<endl; return 0;}
        ans += k;
        mid -= k*(r+l);
        b[i] = mid;
        pq.push({b[i], i});
    }
    cout<<ans<<endl;
}
