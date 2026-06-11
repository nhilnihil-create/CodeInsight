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


ll n, m, ans;

void calc(string t, char mx)
{
    if(t.size() == n)
        cout << t << "\n";
    else
    {
        for(char c = 'a'; c <= mx; c++)
        {
            calc(t + c, (c == mx) ? char(mx + 1) : mx);
        }
    }

}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen(acmpIN, "r", stdin);
//    freopen(acmpOUT, "w", stdout);

    cin >> n;


    string s;
    calc(s, 'a');

    return 0;
}

