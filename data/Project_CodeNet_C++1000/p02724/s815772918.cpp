//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include <iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
//#include<unordered_map>
//#include<stack>
#include<algorithm>
#define ll long long
#define eps 1e-9
#define endl "\n"
#define PI acos(-1)
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
   ll n,hp=0,sum=0;
   cin>>n;
   int fivehun=n/500;
   sum+=(fivehun*1000);
   int rem=n%500;
   int five=rem/5;
   sum+=(five*5);
   cout<<sum<<endl;
return 0;
}
