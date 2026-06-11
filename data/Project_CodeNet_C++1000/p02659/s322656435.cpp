#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
ll a,b;
cin>>a>>b;
char c;
cin>>c;
int d;
cin>>d;
b*=100;
b+=d;
ll x=b*a;
cout << x/100 << endl;

    return 0;

}
