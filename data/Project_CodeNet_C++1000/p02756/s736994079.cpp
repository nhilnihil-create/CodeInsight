#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    string s,b;
    int q;
    cin >> s >> q;
    bool flag=true;
    rep(i,q) {
        int t;
        cin >> t;
        if (t==1) flag=!flag;
        else {
            int f;
            char c;
            cin >> f >> c;
            if ((f==1)^flag) s.push_back(c);
            else b.push_back(c);
        }
    }
    if (flag==1) {
        reverse(b.begin(),b.end());
        rep(i,s.size()) b.push_back(s[i]);
        cout << b << endl;
    } else {
        reverse(s.begin(),s.end());
        rep(i,b.size()) s.push_back(b[i]);
        cout << s << endl; 
    }
   
    return 0;   
}