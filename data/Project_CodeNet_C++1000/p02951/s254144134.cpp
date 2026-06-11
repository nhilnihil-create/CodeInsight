#include <bits/stdc++.h>
#define MAXN 100010
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
using namespace std;
const ll mod = 1e18 + 7;


int main (){
    int a, b, c;
    cin >>a >> b >> c;

    cout << max(0, c -(a - b)) << endl;
    return 0;
}