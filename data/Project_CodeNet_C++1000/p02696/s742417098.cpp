#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;

int main(){
  ll A,B,N;
  
  cin >> A >> B >> N;
  
  if(B>N)
    cout << floor(A*N/B) << endl;
  else
    cout << floor(A*(B-1)/B) << endl;
}