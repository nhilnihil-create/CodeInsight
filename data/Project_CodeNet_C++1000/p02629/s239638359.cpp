#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void f(ll n)
{
   if(n==0)return;
   n--;
   f(n/26);
   putchar('a'+(n%26));
}
int main()
{
    ll n;
    cin>>n;
    f(n);
}
