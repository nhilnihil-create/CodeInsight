#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const int INF=2e9;
const double PI=acos(-1);


vector<pair<int,string>> vectorCnt(vector<string> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<pair<int,string>> b;
    int cnt=1;
    rep(i,n-1) {
            if (a[i+1]!=a[i]) {
                b.push_back(make_pair(-cnt,a[i]));
                cnt=1;
            } else {
                ++cnt;
            }
    }
    b.push_back(make_pair(-cnt,a[n-1]));
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(s.begin(),s.end());
    vector<pair<int,string>> p=vectorCnt(s);
    sort(p.begin(),p.end());
    int m=p.size();
    int c=p[0].first;
    rep(i,m) {
        if (p[i].first==c) cout << p[i].second << endl;
    }
     
    return 0;   
}