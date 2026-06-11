#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main( )
{
     int n;
     cin>>n;
     int t, nxt = 1, cnt = 0;
     for (int i = 0; i < n; i++) {
     cin >> t;
     if (t == nxt)
         nxt++;
     else
         cnt++;
}
cout << (cnt == n ? -1 : cnt);
}