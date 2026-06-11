#include <bits/stdc++.h> 
using namespace std; 

#define rep(i,n) for(int i=0;i<n;i++)
int n,m,q;
vector<int> a,b,c,d;
int ans;
 
void dfs(vector<int> w){
    if(w.size()==n+1){
        int cnt = 0;
        rep(i,q){
            if(w[b[i]]-w[a[i]]==c[i]){
                cnt += d[i];
            }
        }
        ans = max(ans,cnt);
        return;
    }
    w.push_back(w.back());
    while(w.back()<=m){
        dfs(w);
        w.back()++;
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>> m >> q;
    a = b = c = d = vector<int> (q);
    rep(i,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];  }
    ans = 0;
    vector<int> w(1,1);
    dfs(w);
    cout << ans;
    return 0;
}