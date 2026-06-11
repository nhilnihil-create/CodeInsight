#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;
typedef long double ld;
typedef vector<int> vr;
typedef pair<int, int> pr;
#define pb push_back
#define ff first
#define ss second
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433
#define endl "\n"
//cout << fixed << setprecision(2);


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r, d;
    cin >> l >> r >> d;
    int cnt = 0;
    for(int i = l; i <= r; i++){
        if(i % d == 0){
            cnt++;
            //cout << i << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}

