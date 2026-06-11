#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> h(n, 0);
    rep(i, n)cin >> h[i];
    
    vector<queue<int>> dict(n);
    
    vector<int> a(m, 0), b(m, 0);
    rep(i, m){
        cin >> a[i] >> b[i];
        dict[a[i]-1].push(b[i]-1);
        dict[b[i]-1].push(a[i]-1);
    }
    
    
    int ans = 0;
    rep(i, n){
        if(dict[i].size()==0){
            ans++;
        }else{
            bool flg = true;
            while(!dict[i].empty()){
                int x = dict[i].front();
                dict[i].pop();
                if(h[i]<=h[x])flg=false;
            }
            if(flg)ans++;
        }
    }
    
    cout << ans << endl;
}