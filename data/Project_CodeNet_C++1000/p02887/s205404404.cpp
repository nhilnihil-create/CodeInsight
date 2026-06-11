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


int main(){
 ll n;
 cin>>n;
 string s;
 cin>>s;
 ll d=0;
 rep(i,n-1){
   if(s[i]==s[i+1])d++;
 }
 cout<<s.size()-d<<endl;
}

