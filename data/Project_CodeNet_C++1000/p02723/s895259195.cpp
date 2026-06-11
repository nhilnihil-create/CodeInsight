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
const double pi = 2 * acos(0.0);
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


    string s;
    cin >> s;

    if((s[2]==s[3]) && (s[4]==s[5]))
        cout << "Yes" << nl;
    else
        cout << "No" << nl;

    ///Happily DONE

    return 0;
}
