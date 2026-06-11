#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
#include<deque>
#include<chrono>
using namespace std;
#define pi 3.141592653589793238


#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>
typedef vector<ll> vi;
typedef vector<vi> vvi;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    
    //cin >> T;
    while (T--) {
        ll a , v, b ,w, t;
        cin >> a>>v>>b >> w;
        cin >> t;
        ll mina , maxa;
        mina = a - v * t;
        maxa = a + v * t;
        ll minb, maxb;
        minb = b - w * t;
        maxb = b + w * t;
        if(a < b){
            if(maxa >= maxb){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        } 
        else{
            if(minb >= mina){
                cout << "YES";

            }
            else{
                cout << "NO";
            }
        }
    }

    return 0;
}
