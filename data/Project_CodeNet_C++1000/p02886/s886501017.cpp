#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000101001;
int main(){
int n;cin>>n;
int d[n];
rep(i,n)cin>>d[i];
int sum=0;
rep(i,n){
    for(int j=i+1;j<n;j++){
       sum+=d[i]*d[j];
    }
}
cout << sum << endl;
}