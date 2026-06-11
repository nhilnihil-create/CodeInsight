#include<bits/stdc++.h>
#define int    long long

using namespace std;
int32_t main()
{ int amount =100;
int x;
cin >> x;
int ans=0;
while(amount<x)
{ amount += amount/100;
ans++;


}
cout << ans << endl;
}
