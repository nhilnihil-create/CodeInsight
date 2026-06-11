#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int query;
    cin >> query;
    bool state = true;
    string l,r;
    rep(i,query){
        int q;
        cin >> q;
        if(q==1){
            if(state) state = false;
            else state = true;
        }
        else{
            int side;
            cin >> side;
            char c;
            cin >> c;
            if(side==1){
                if(state) l.push_back(c);
                else r.push_back(c);
            }
            else{
                if(state) r.push_back(c);
                else l.push_back(c);
            }
        }
    }
    string ans;
    reverse(l.begin(),l.end());
    ans = l+s+r;
    if(state){
        cout << ans << endl;
    }
    else{
        reverse(ans.begin(),ans.end());
        cout << ans << endl;
    }
    return 0;
}