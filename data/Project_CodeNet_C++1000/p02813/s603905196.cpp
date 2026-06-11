#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int main(int argc, const char** argv) {
    int n,p[10],q[10],r[10];
    cin >> n;
    rep(i,n) {
        int a;cin>>a;
        p[i]=a;
    }
    rep(i,n) {
        int a;cin>>a;
        q[i]=a;
    }
    rep(i,n) {
        r[i] = i + 1;
    }
    int count=0,pnum,qnum;
    do{
        bool pok=true,qok=true;
        rep(i,n) {
            if(p[i]!=r[i]) {
                pok=false;
            }
        }
        rep(i,n) {
            if(q[i]!=r[i]) {
                qok=false;
            }
        }
        if(pok) pnum=count;
        if(qok) qnum=count;
        count++;
    }while(next_permutation(r,r+n));

    cout<< abs(pnum-qnum) <<endl;
    return 0;
}