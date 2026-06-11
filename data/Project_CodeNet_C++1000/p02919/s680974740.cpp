#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

#define lf double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n; cin>>n;
    vi M(n+1);
    rep(i, n){
        int p; cin>>p;
        M[p] = i;
    }
    multiset<int> D;
    D.ins(-1); D.ins(-1);
    D.ins(n);  D.ins(n);

    ll ans=0;
    for(int i=n; i>=1; i--){
        auto itr = D.lower_bound(M[i]); itr++;
        int r2 = *itr; itr--;
        int r1 = *itr; itr--;
        int l1 = *itr; itr--;
        int l2 = *itr;

        int Right = (M[i]-l1)*(r2-r1);
        int Left = (l1-l2)*(r1-M[i]);
        ans += (ll)(Right+Left)*i;
        //cout << Right+Left << endl;
        D.ins(M[i]);
    }
    cout << ans << "\n";
	return 0;
}
