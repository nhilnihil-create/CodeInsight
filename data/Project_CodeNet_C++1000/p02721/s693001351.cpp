
#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;

 
int main() {
    int n,k,c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> a,b;
    int u=0;
    rep(i,n){
        if (u<=0 && s[i]=='o'){
            a.push_back(i+1);
            u=c+1;
        }
        u--;
    }
    u=0;
    rep(i,n){
        if (u<=0 && s[n-i-1]=='o'){
            b.push_back(n-i);
            u=c+1;
        }
        u--;
    }
    if (a.size()!=k) return 0;
    reverse(all(b));
    rep(i,a.size()){
        if (a[i]==b[i]) cout << a[i] << endl;
    }
}