#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<ll,ll>;


ll m=1000000007;

ll mod=1e9+7;
ll dp[2000+4];


int main()
{
 ll n;
 cin>>n;
 ll sum=0;
 Rep(i,n+1){
     ll e=n/i;
     sum+=(i+e*i)*e/2;
 }
 cout<<sum<<endl;
}
 


 

 


