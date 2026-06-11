#include <bits/stdc++.h>
using namespace std ;
 
#define pb(n) push_back(n)
#define fi first
#define se second
#define X real()
#define Y imag()

#define value(x,y,w,h) (x >= 0 && x < w && y >= 0 && y < h)

#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
 
#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))
 
typedef long long ll ;
typedef deque<int> di ;
typedef deque<ll> dl ;
typedef map<string,int> dict;
typedef complex<double> comd;
typedef pair<int,int> pii;
 
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};
int res;
int n,s;
void solve(int a,int b,int c){
    if(b > n || a > s) return;
    if(a == s && b == n){
        ++res;
        return;
    }
    REP(i,c+1,10){
            solve(a+i,b+1,i);
    }
    return ;
}

int main(){
    while(cin>> n >> s){
        if( n + s == 0) break;
        res = 0;
        if(s <= 55){
            rep(i,10){
                solve(i,1,i);
            }
        }
        cout << res << endl;
    }

    return 0;
}