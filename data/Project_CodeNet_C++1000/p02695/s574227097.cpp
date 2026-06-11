#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int n,m,q;
int ans=0;
vector<int> a,b,c,d;

int dfs(vector<int> p){
    if(p.size() == n+1){
        int tmp_ans=0;
        rep(i,q){
            if(p[b[i]]-p[a[i]]==c[i]) tmp_ans+=d[i];
        }
        if(ans < tmp_ans) ans = tmp_ans;
        return 0;
    }
    p.push_back(p.back());
    while(p.back() < m+1){
        dfs(p);
        p.back()++;
    }
    return 0;
}

int main(){
    cin>>n>>m>>q;
    int x,y,z,w;
    vector<int> p(1,1);
    rep(i, q){
        cin>>x>>y>>z>>w;
        a.push_back(x);
        b.push_back(y);
        c.push_back(z);
        d.push_back(w);
    }
    dfs(p);
    cout << ans << endl;
}