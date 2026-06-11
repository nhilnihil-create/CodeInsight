#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define pb push_back
#define ff first
#define ss second
#define SIZE 500002
#define INF 2e9 + 9
#define acmpIN "input.txt"
#define acmpOUT "output.txt"

//#pragma GCC optimize("Ofast")
//

vector<int> lol = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen(acmpIN, "r", stdin);
//    freopen(acmpOUT, "w", stdout);

    int k;
    cin >> k;
    k--;
    cout << lol[k];

    return 0;
}

