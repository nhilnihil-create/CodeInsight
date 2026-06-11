#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
set<int> st;
signed main(){
    int n;cin >> n;
    int p[n];
    rep(i,n)cin >> p[i];
    rep(i,n)p[i]--;
    int idx[n];
    rep(i,n)idx[p[i]] = i;
    //rep(i,n){
    //    cin >> p[i];
    //    p[i]--;
    //    
    //    idx[p[i]] = i;
    //}
    int ans = 0;
    for(int i = n-1;i >= 0;i--){
        int c = 0;
        vector<int> l(2,-1);
        vector<int> r(2,n);
        st.insert(idx[i]);
        {
            auto hoge = st.find(idx[i]);
            rep(j,2){
                if(hoge == st.begin())break;
                hoge--;
                l[j] = *hoge;
            }

        }
        {
            auto hoge = st.find(idx[i]);
            rep(j,2){
                hoge++;
                if(hoge == st.end())break;
                r[j] = *hoge;
            }
            
        }
        vector<int> ls(2),rs(2);
        ls[0] = idx[i] -l[0];
        ls[1] = l[0] - l[1];
        rs[0] = r[0] - idx[i];
        rs[1] = r[1] - r[0];
        c =ls[0]*rs[1]+ls[1]*rs[0];
        



        
        ans += c*(i+1);
    }
    cout << ans << endl;
    
    
    return 0;
}