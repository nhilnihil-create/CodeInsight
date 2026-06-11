#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define SIZE_OF_ARRAY(a) (sizeof(a)/sizeof(a[0]))

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a[n] = {0};
    for(int i = 0;i < n;i++){
        cin >> a[i] ;
    }
    stable_sort(a,a + n);
    ll count = 0;
    for(int i = 0;i < n;i++){
        count += a[i];
    }
    cout << a[0] <<" " << a[n - 1]  << " " << count << endl;
}
