#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
void solve(){
    int a[3][3];
    map<int, int>u, d1, d2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>a[i][j];
            if(i==j)d1[a[i][j]]++;
            if(i+j==2)d2[a[i][j]]++;
        }
    }
    int n;
    cin>>n;
    vi v(n);
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        u[v[i]]++;
        if(d1[v[i]])ans1++;
        if(d2[v[i]])ans2++;
    }
    if(ans1==3||ans2==3){
        cout<<"Yes\n";
        return;
    }
    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int j = 0; j < 3; j++){
            if(u[a[i][j]])cnt++;
        }
        if(cnt==3){
            cout<<"Yes\n";
            return;
        }
        cnt=0;
        for(int j = 0; j < 3; j++){
            if(u[a[j][i]])cnt++;
        }
        if(cnt==3){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}
signed main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)solve();
}