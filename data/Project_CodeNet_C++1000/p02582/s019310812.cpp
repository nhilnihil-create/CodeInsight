#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int main()
{
	
    string s;
    cin >> s;
    int res = 0;
    if (s == "RRR") res = 3;
    else if (s == "RRS") res =  2;
    else if (s == "RSS") res =  1;
    else if (s == "RSR") res =  1;
    else if (s == "SRS") res =  1;
    else if (s == "SSR") res =  1;
    else if (s == "SRR") res =  2;
    else if (s == "SSS") res =  0;
    cout << res << endl;
}