#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
   ll a, b, c, d;
   cin >> a >> b >> c >> d;

   cout <<  max(max((b*c),(b*d)),max((a*d),(a*c)))<< endl;

}


