#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

#define nl "\n"
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define VI vector<int>
#define VII vector<ll>
#define MAP map <int,int>
#define PI pair < int , int >
#define sz(v) (int)(v).size()
#define all(v) v.begin(),v.end()
#define mem(a,val) memset(a,val,sizeof(a))
#define precise(n) fixed(cout);cout<<setprecision(n)

const int N = (int)4e7;
const int MOD = (int)1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-9;

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    io;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///Let the showdown begin

    int x,y,h,m;
    cin >> x >> y >> h >> m;

    db ah1,ah2,am,temp1,temp2,ans;

    ah1 = pi*(1.0/6)*h;
    ah2 = pi*(1.0/360)*m;
    am =  pi*(1.0/30)*m;
    temp1= x*x;
    temp2= y*y;

    temp1+=temp2;
    temp1-=2*x*y*cos(ah1+ah2-am);

    precise(20);
    cout << sqrt(temp1) << nl;

    ///Happily DONE

    return 0;
}
