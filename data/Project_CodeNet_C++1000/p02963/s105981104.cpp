#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, int> pii;


int main()
{
    lli s;
    cin >> s;
    lli x = 1e9;
    cout << "0 0 " << x << " 1 ";

    lli c = (s+x-1)/x;
    lli m = s%x;
    cout << (x*c)-s << " " << c << "\n";

    return 0;
}
