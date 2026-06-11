#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<vector<int>> v(10,vector<int>(10,0));
    rep(j,n+1){
        int i = j;
        vector<int> copy;
        while(i>0){
            copy.push_back(i%10);
            i/=10;
        }
        if(j==0) continue;
        int a = copy[0];
        int b = copy.back();
        if(a==0) continue;
        v[a][b]++;
    }
    int ans = 0;
    rep(i,10){
        rep(j,10){
            ans += v[i][j] * v[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}