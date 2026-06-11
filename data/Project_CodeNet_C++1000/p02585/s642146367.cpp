#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);

ll get_part_mas(vector<ll> c, vector<ll> s, ll k) {
    int m=s.size();
    ll right=1,sum=c[s[0]];
    ll tres=-1e9;
    rep(left,2*m) {
        while (right<2*m && right-left<k) {
            if (c[s[right%m]]<0) break;
            sum+=c[s[right%m]];
            ++right;
        }
        tres=(tres>sum)?tres:sum;
        if (left+1==right && right<2*m) {
            sum+=c[s[right%m]];
            ++right;
        }
        sum-=c[s[left%m]];
    }
    return tres;
}


ll get_maxval(vector<ll> c, vector<ll> s, ll k) {
    ll m=s.size();
    ll k1=(k<m-1)?k:m-1,k2=k%m;
    if (k2==0) k2=m;
    ll tmp=0;
    rep(i,m) tmp+=c[s[i]];
    ll res1=-1e9;
    if (k1>0) res1=get_part_mas(c,s,k1);
    ll res2=get_part_mas(c,s,k2);
    if (tmp>0) {
        ll num1=(k-k1)/m,num2=(k-k2)/m;
        res1+=tmp*num1;
        res2+=tmp*num2;
    }
    ll res=(res1>res2)?res1:res2;
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);

    ll n,k;
    cin >> n >> k;
    vector<ll> p(n),c(n);
    rep(i,n) {
        cin >> p[i]; 
        --p[i];
    }
    rep(i,n) cin >> c[i];
    ll ans=-1e12;
    rep(i,n) {
        ll next=i;
        ll scnt=0;
        vector<ll> cnt;
        while (1) {
            scnt+=c[next];
            cnt.push_back(scnt);
            next=p[next];
            if (next==i) break;
        }
        ll m=cnt.size();
        rep(j,m) {
            if (j+1>k) break;
            ll tans=cnt[j];
            if (scnt>0) tans+=scnt*ll((k-j-1)/m);
            ans=(ans>tans)?ans:tans;
        }
    }
    cout << ans << endl;

    return 0; 
}
