#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;

int main() {

int n ;
cin >> n ;
vector<ll> a(n) ;
vector<ll> c(n+1) ;

for (int i = 0; i < n; i++)
{
    cin >> a[i]; 
    c[a[i]]++ ;
}

ll tmp = 0 ;
for (int i = 1; i <= n ; i++)
{
    tmp += c[i]*(c[i]-1)/2 ;
}

for (int i = 0; i < n ; i++)
{
   ll b = c[a[i]]*(c[a[i]]-1)/2 ;
   ll af = (c[a[i]]-1)*(c[a[i]]-2)/2 ;
   cout << tmp -b + af << endl ;
}


return 0; 
}