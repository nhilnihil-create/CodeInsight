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
    
    int x;
    cin >> x;

    int remain = x%100;
    int aaa = x/100;
    if (5*aaa < remain) {
        cout << 0 << endl;
    }
    else cout << 1 << endl;

    return 0;
}