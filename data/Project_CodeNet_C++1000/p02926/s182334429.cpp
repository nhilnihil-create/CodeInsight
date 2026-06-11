//
// Created by yamunaku on 2019/09/07.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

const ld pi=3.14159265358979323846;

int main(){
    int n;
    cin >> n;
    vector<ld> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    vector<ld> rad(n);
    rep(i,n){
        rad[i]=atan2(y[i],x[i]);
    }
    vector<int> idx(n);
    iota(all(idx), 0);
    sort(all(idx),[&](int l, int r){
        return rad[l]<rad[r];
    });
    vector<ld> nx(2*n),ny(2*n);
    vector<ld> nrad(2*n);
    rep(i,2*n){
        nx[i]=x[idx[i%n]];
        ny[i]=y[idx[i%n]];
        nrad[i]=rad[idx[i%n]]+(i/n)*2*pi;
//        cout << nx[i] SP ny[i] SP nrad[i] << endl;
    }
    int r=0;
    ld ans=0;
    ld xx=0,yy=0;
    rep(i,n){
        while(r<i+n){
            if(nrad[r]-nrad[i]>pi) break;
            xx+=nx[r];
            yy+=ny[r];
            ans=max(ans,sqrt(xx*xx+yy*yy));
            r++;
        }
        ans=max(ans,sqrt(xx*xx+yy*yy));
        xx-=nx[i];
        yy-=ny[i];
        r--;
        xx-=nx[r];
        yy-=ny[r];
    }
    CST(15);
    cout << ans << endl;
    return 0;
}
