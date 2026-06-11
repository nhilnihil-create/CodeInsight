// Created by ...
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // long long t;
    string t;
    long long sum=0;
    cin>>t;
   	for (int i = 0; i <t.length(); ++i)
   	{
   		/* code */
   		sum+=(t[i]-'0');

   	}
   	if (sum%3==0)
   	{
   		puts("Yes");
   		/* code */
   	}
   	else
   		puts("No");
    return 0;
}