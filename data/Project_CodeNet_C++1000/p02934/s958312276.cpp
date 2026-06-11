#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
bool isPrime(long long x){
  if(x == 1)return 0;
  for(long long i = 2; i*i <= x; i++) if(x%i == 0) return 0;
  return 1;
}

int main(){
int n;cin>>n;
double a[n];
rep(i,n)cin>>a[i];
double b[n];
rep(i,n)b[i]=(double)1/a[i];
double sum=0;
rep(i,n)sum+=b[i];
double ans=0;
ans=(double)1/sum;
cout << setprecision(12) <<ans<< endl;
}