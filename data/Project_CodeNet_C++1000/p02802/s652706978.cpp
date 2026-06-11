#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int,string>;
int main(){
    int n,m;
    cin >> n >> m;
    vector <p> vec(m);
    int ans1,ans2;
    ans1 = 0;
    ans2 = 0;
    rep(i,m){
        int x;
        string s;
        cin >> x >> s;
        p pp = {x,s};
        vec[i] = pp;
    }
    set<int> st;
    map <int,int> wa;
    rep(i,m){
        if (vec[i].second == "WA"){
            wa[vec[i].first]++;
        }
        else{
            if (st.find(vec[i].first) == st.end()){
                ans2 += wa[vec[i].first];
                ans1 += 1;
                st.insert(vec[i].first);
                
            }
        }
    }
    cout << ans1 << ' ' << ans2 << endl;

}