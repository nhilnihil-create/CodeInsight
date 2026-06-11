#include<bits/stdc++.h>
using namespace std;


#define li          long long int
#define rep(i,to)   for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)    for(li i=(li)(start);i<((li)(to));i++)
#define pb          push_back
#define sz(v)       ((li)(v).size())
#define bgn(v)      ((v).begin())
#define eend(v)     ((v).end())
#define allof(v)    (v).begin(), (v).end()
#define dodp(v,n)       memset(v,(li)n,sizeof(v))
#define bit(n)      (1ll<<(li)(n))
#define mp(a,b)     make_pair(a,b)
#define rin rep(i,n)
#define EPS 1e-12
#define ETOL 1e-8
#define MOD 1000000007
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1


#define idp if(DBGP)
#define F first
#define S second
#define p2(a,b)     idp cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)       idp cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define p4(a,b,c,d)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl
#define p5(a,b,c,d,e)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl
#define p6(a,b,c,d,e,f)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<endl
#define p7(a,b,c,d,e,f,g)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<endl
#define p8(a,b,c,d,e,f,g,h)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<endl
#define p9(a,b,c,d,e,f,g,h,i)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<endl
#define p10(a,b,c,d,e,f,g,h,i,j)        idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<"\t"<<j<<endl
#define foreach(it,v)   for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define p2p(x)      idp p2((x).F, (x).S)
#define dump(x,n)   idp{rep(i,n){cout<<x[i]<<" ";}puts("");}
#define dump2(x,n)  idp{rep(i,n){cout<<"["<<x[i].F<<" , "<<x[i].S<<"] ";}puts("");}
#define dumpi(x)    idp{foreach(it, x){cout<<(*it)<<" ";}puts("");}
#define dumpi2(x)   idp{foreach(it, x){cout<<"["<<(it)->F<<" , "<<(it)->S<<"] ";}puts("");}

#define read2d(a,w,h)   rep(i,h)rep(j,w)cin>>a[i][j]
#define dump2d(a,w,h)   rep(i,h){rep(j,w)cout<<a[i][j]<<" ";puts("");}

typedef pair<li, li> PI;


// i番目まででj回操作して左端の高さがa[k]な場合の最小走査回数
li dp[330][330][330];

li n, k;
li h[333];

int main() {
    cin >> n >> k;
    h[0] = 0;
    rin{
        cin >> h[i + 1];
    }

    rep(i, n + 1) {
        rep(j, n + 1) {
            rep(kk, n + 1) {
                dp[i][j][kk] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    repp(i, 1, n + 1) {
        rep(j, n + 1) {
            rep(kk, i) {
                // 操作しない場合
                if (dp[i - 1][j][kk] == INF) {
                    continue;
                }
                if (h[kk] <= h[i]) {
                    dp[i][j][i] = min(dp[i][j][i], dp[i - 1][j][kk] + h[i] - h[kk]);
                } else {
                    dp[i][j][i] = min(dp[i][j][i], dp[i - 1][j][kk]);
                }
                // 操作する場合
                if (j < k) {
                    dp[i][j + 1][kk] = min(dp[i][j + 1][kk], dp[i - 1][j][kk]);
                }
                //p6(i, j, i, dp[i][j][i], kk, dp[i - 1][j][kk]);
            }
        }
    }
    li res = INF;
    rep(j, k + 1) {
        rep(kk, n + 1) {
            res = min(res, dp[n][j][kk]);
        }
    }
    cout << res << endl;

    return 0;
}