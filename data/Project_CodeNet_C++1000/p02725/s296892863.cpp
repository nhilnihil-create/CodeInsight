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

int main(){
 
 
  ll k,n;
  cin>>k>>n;
 
  vector<ll> A(n);
  rep(i,n){
      cin>>A[i];
  }
 ll ma=0;
  Rep(i,n){
    ma=max(ma,A[i]-A[i-1]);
  }
  ma=max(ma,k-A[n-1]+A[0]);
  cout<<k-ma<<endl;

 
}

