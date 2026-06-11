#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];

int main()
{
   int a, x, b, y, k;
   cin >> a >> x >> b >> y >> k;
   int xx = a * 60 + x;
   int yy = b * 60 + y;
   cout << yy - xx - k << endl;
}
