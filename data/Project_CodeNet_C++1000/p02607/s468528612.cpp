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
    int n;
    cin >> n;
    vector<int> v(n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        if( i % 2 == 0 && v[i] % 2 != 0){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

