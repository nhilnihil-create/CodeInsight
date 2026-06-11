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
using P =pair<int,int>;
ll ketasu(ll a){
   ll num=1;
   while(a/10){
       num++;
       a/=10;
   }
   return num;
}


int main()
{
 ll n;
 cin>>n;
 vector<double> x(n),y(n);
 rep(i,n){
    cin>>x[i]>>y[i];
 }
 vector<int>t(n);
 rep(i,n){
     t[i]=i;
 }

 long double sum=0;
 ll k=0;
 do{
     k++;
     rep(i,n-1){
        sum+=sqrt(pow((x[t[i]]-x[t[i+1]]),2)+pow((y[t[i]]-y[t[i+1]]),2)); 
     }

 }while(next_permutation(t.begin(), t.end()));
 cout << fixed << setprecision(10) << sum/k<<endl;
}

