#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  int a,b,sum=0;
  rep(i,n){
    if(i==n-1){
        sum+=b;
        break;
    }
    cin>>a;
    if(i==0) sum+=a;
    else sum+=min(a,b);

    b=a;

  }
  cout<<sum;
}