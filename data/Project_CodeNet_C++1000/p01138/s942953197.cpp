#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define sset(s) cout<<#s<<":";each(i,s)cout <<" "<<i;cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

int n;
int a[24*60*60+1];

int tt(string s1)
{
    string ss;
    ss = s1.substr(0,2);
    int h = stoi(ss);
    ss = s1.substr(3,2);
    int m = stoi(ss);
    ss = s1.substr(6,2);
    int s = stoi(ss);
    return h*60*60 + m*60 + s;
}

int main()
{
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        rep(i,24*60*60+1){
            a[i] = 0;
        }
        rep(i,n){
            string s1,s2;
            cin >> s1 >> s2;
            a[tt(s1)]++,a[tt(s2)]--;
        }
        int res = 0;
        int nw = 0;
        rep(i,24*60*60+1){
            nw += a[i];
            res = max(res,nw);
        }
        cout << res << "\n";
    }
}