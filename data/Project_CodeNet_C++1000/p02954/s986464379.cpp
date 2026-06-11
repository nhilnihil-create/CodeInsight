#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> ans(s.length(),0);
    rep(i,s.length()-1){
        if(s[i] == 'R' && s[i+1] == 'L'){
            ans[i]++;ans[i+1]++;
        }
    }
    int l1 = 0,l2 = 0,r1 = 0,r2 = 0;
    int l = 0,r = 0;
    rep(i,s.length()){
        if(ans[i] == 0){
            if(s[i] == 'L'){
                if(l1 == 0) l = i-1;
                if(l1 == l2) l1++;
                else l2++;
            }else {
                if(r1 == 0) r = i-2;
                if(r1 == r2) r1++;
                else r2++;
            }
        }else {
            if(l1 != 0){
                ans[l-1] += l1;
                ans[l] += l2;
                l1 = 0;
                l2 = 0;
                l = 0;
            }
            if(r1 != 0){
                if(r1 > r2) {
                    ans[i+1] += r1;
                    ans[i] += r2;
                    r1 = 0;
                    r2 = 0;
                    r = 0;
                }else{
                    ans[i] += r1;
                    ans[i+1] += r2;
                    r1 = 0;
                    r2 = 0;
                    r = 0;
                } 
            }
        }
        if(i == s.length()-1) {
            if(l1 != 0){
                ans[l-1] += l1;
                ans[l] += l2;
                l1 = 0;
                l2 = 0;
                l = 0;
            }
        }
    }
    rep(i,s.length()){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
