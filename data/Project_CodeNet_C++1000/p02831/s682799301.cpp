#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;


int main()
{
 long long a,b;
 cin >> a >> b;
 
 long long c = gcd(a,b);
 
 cout << a * b / c;
 
}