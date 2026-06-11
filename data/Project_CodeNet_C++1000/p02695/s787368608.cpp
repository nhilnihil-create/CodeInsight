#include <bits/stdc++.h>
using namespace std;
int n,m,q;
vector<vector<int>> g;
void dfs(vector<int> c){
    int f = c.size();
    if(f==n) g.push_back(c);
    else{
        for(int i=c[f-1];i<=m;i++){
            vector<int> b = c;
            b.push_back(i);
            dfs(b);
        }
    }
}
int main(void){
    long ans = 0;
    cin >> n >> m >> q;
    vector<int> e;
    int a[q],b[q],c[q],d[q];
    for(int i=0;i<q;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        b[i]--;a[i]--;
    }
    e.push_back(1);
    dfs(e);
    for(auto i:g){
        long cur = 0;
        for(int j=0;j<q;j++){
            if(i[b[j]]-i[a[j]]==c[j]) cur += d[j];
        }
        ans = max(ans,cur);
    }
    cout << ans << endl;
}