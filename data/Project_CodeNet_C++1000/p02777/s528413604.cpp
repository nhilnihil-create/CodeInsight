#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
	#define W(x, y) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << y;
#else
	#define W(x, y)
#endif

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pi acosl(-1)
#define ld long double
#define prime (1000000000 + 7)
#define INF 1000000000

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t, u;
    ll a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> u;
    if(u == s){
        a--;
    } else{
        b--;
    }
    cout << a << " " << b << endl;

   
    return 0;
}


/*
    r   o   #   r   o   u   n   d
-1  0   0   0   1   2   0   0   0 
*/
// 1 = 3
// 2 = 3
// 3 = -1
// 4 = 0
// 5 = 1