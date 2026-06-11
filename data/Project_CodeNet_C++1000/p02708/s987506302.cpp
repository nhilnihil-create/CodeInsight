#include <bits/stdc++.h>
using namespace std;
int main() {
  long long Mod=1000000007;
  long long n,k;
  cin >> n >> k;
  long long m = n+1-k;
  long long M=m*(m+1)/2;
  cout << ((n+1)*M+(m+1)-M*(2*m+1)/3)%Mod << endl;
} 