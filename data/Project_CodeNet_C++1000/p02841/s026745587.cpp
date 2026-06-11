#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll

#define vi vector <int>
#define ii pair <int, int>
#define vii vector <ii>
#define INFLL 9e18
#define INF 2e9
#define EPS 1e-9
#define pb push_back
#define emp emplace_back
#define PI acos(-1.0)
#define endl "\n"
#define mp make_pair
#define DEBUG 0


int main ()

{
    #define int ll
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    
    int d1, m1, d2, m2;
    cin >> m1 >> d1 >> m2 >> d2;
    if (m1 == 2){
        if (d1 == 28) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12){
        if (d1 == 31) cout << 1 << endl;
        else
        {
             cout << 0 << endl;
        }
        
    }
    else{
        if (d1 == 30) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}