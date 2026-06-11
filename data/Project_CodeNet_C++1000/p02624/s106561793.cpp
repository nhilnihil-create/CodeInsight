#include <bits/stdc++.h>
#include<cmath>
#include<iomanip>
#include <algorithm>
#include<string.h>
#include<queue>
#include<deque>
#include<set>

using namespace std;
//cout<<setprecision(9)<<fixed<<a;
typedef long long ll;


int main()

{
   ll n,sum=0,m;
   cin>>n;
   for(int i=1; i<=n; i++)
   {
       m=n/i;
       sum+=i*(m*(m+1))/2;
   }
   cout<<sum;


}









