#include <bits/stdc++.h>
using namespace std;
#define hyperspeed ios::sync_with_stdio(false);cin.tie(NULL);
#define ll long long  
#define ull unsigned long long
#define ui unsigned int
#define li long int
#define uli unsigned long int
#define pb push_back
#define ld long double
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
const int MOD = 1e9+7;

void solve() {
    int n;
    cin >> n;
    bool ok = true;
    int a;
    while(n--) {
        cin >> a;
        if(!ok)
            continue;
        if(a%2!=0) {
            continue;
        }
        if(a%3==0 || a%5==0) {
            continue;
        }
        else {
            ok=false;
        }
    } 
    if(ok) {
        cout << "APPROVED\n";
    }
    else {
        cout << "DENIED\n";
    }
}

int32_t main()
{
    hyperspeed
    int test=1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}

//--n1m5
