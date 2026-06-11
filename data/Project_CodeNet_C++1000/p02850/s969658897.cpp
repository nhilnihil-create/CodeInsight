#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n;
    cin>>n;
    vector<P> p(n);
    rep(i,n-1) cin>>p[i].first>>p[i].second;
    vector<vector<int>> node(n+5);
    rep(i,n+5) node[i].clear();
    vector<int> ans(n+5,0);
    rep(i,n-1){
        node[min(p[i].first, p[i].second)].push_back(max(p[i].first, p[i].second));
    }
    node[1].push_back(0);
    int cnt=1;
    deque<int> d;
    d.push_back(1);
    while(!d.empty()){
        int a=d.front(),c=1;
        d.pop_front();
        for(auto v: node[a]){
            d.push_back(v);
            if(c==ans[a]) c++;
            ans[v]=c;
            c++;
        }
    }
    rep(i,n-1) cnt=max(cnt, ans[i+2]);
    cout<<cnt<<endl;
    rep(i,n-1) cout<<ans[max(p[i].first, p[i].second)]<<endl;
    return 0;
}