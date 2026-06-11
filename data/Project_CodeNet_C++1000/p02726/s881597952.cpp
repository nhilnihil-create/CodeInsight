#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
using LP = pair<ll,ll>;
using P = pair<ll,int>;
ll mod = 998244353;

int main()
{
    int n, x, y;
    cin>> n >> x>>y;
    x--;y--;
    vector<int> table(n,0);
    rep(i, n) rep(j,i){
        int tmp = min(i-j, abs(x-i)+abs(y-j)+1);
        tmp = min(tmp,abs(x-j)+abs(y-i)+1);
        table[tmp]++;
    }
    repran(i, 1, n) cout << table[i] << endl;
}