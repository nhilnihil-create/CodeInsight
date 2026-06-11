#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     int h,w;
     cin >> h >> w;
     vector<string>s(h+1);
     for(int i = 0;i<h;i++) {cin >> s[i];}
     int aa[h+1][w+1];
     int bb[h+1][w+1];
     memset(aa,0,sizeof(aa));
     memset(bb,0,sizeof(bb));
     for(int i = 0;i<h;i++){
            int pos = 0;
            int cnt = 0;
        for(int j = 0;j<=w;j++){
            if(s[i][j]!='.'||j==w){
                for(int k = pos;k<j;k++) aa[i][k] = cnt;
                cnt = 0;
                pos = j;
            }
            else cnt++;
    }
}
    for(int i = 0;i<w;i++){
            int pos = 0;
            int cnt = 0;
        for(int j = 0;j<=h;j++){
            //cout <<i;
            if(s[j][i]!='.'||j==h){
                for(int k = pos;k<j;k++) bb[k][i] = cnt;
                cnt = 0;
                pos = j;
            }
            else cnt++;
    }}
     int ans = 0;
     for(int i = 0;i<h;i++)
        for(int j = 0;j<w;j++)
       if(s[i][j]=='.') ans = max(ans,aa[i][j]+bb[i][j]-1);
     cout << ans;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
