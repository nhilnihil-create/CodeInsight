#include<bits/stdc++.h>
using namespace std;

# define line cout<<"\n";
# define fast ios_base::sync_with_stdio(false) ; cin.tie(0) ;

# define ll long long
# define C continue;

# define pb push_back
# define vi vector < int >
# define vll vector < ll >

# define I insert

# define pii pair < int , int >
# define pll pair < ll , ll >
# define F first
# define S second

# define vpii vector < pair < int , int > >
# define vpll vector < pll >

# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()

# define ld long double
# define PQ priority_queue

# define vc vector < char >
# define vb vector < bool >
# define vs vector < string >

# define vvi vector < vector < int > >
# define vvll vector < vector < ll > >
# define vvc vector < vector < char > >
# define vvb vector < vector < bool > >

# define allcomp(v) v.begin() , v.end() , comp

# define pp(n) printf("%.10Lf",n);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string vow = "aeiou";
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int dxhorse[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyhorse[] = {1, -1, 2, -2, 2, -2, 1, -1};

const int dx[] = { -1 , 0 , 1 , 0 , -1 , -1 , 1 , 1 } ;
const int dy[] = { 0 , 1 , 0 , -1 , -1 , 1 , -1 , 1 } ;

const ld pie = 3.1415926535897932384626 ;
const ll mod = 1e9 + 7 ;

/// Tip : If a and b are positive integers ; we may say - ceil (a/b) = 1 + floor ( (a-1)/b ) .
/// Start using lower bound !!

void solve ( int test_case )
{
    ll a , v , b , w ;
    cin >> a >> v >> b >> w ;

    ll dis = abs ( a - b ) ;
    ll vel = v - w ;

    if ( dis == 0 ) { cout << "YES" ; line ; return ; }
    if ( vel < 0 ) { cout << "NO" ; line ; return ; }

    ll t ;
    cin >> t ;

    if ( vel * t >= dis )
        cout << "YES" ;

    else cout << "NO" ;

    line ;
}

int main()
{
    int t = 1;
    // cin >> t;

    for ( int i = 1 ; i <= t ; i ++ )
    {
        solve ( i ) ;
    }

    return 0;
}
