#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(long long i=0;i<n;i++)

int main(){
  long long n;	cin >> n;
  vector<long long>	A(n+1);
  vector<long long> p(n+1,0);
  rep(i,n){
    cin >> A[i+1];
    p[A[i+1]]++;
  }
  
  long long sum=0;
  for(long long i=1;i<=n;i++){
    long long num=p[i];
    sum+=num*(num-1)/2;
  }
  
  for(long long i=1;i<=n;i++){
    cout << sum-(p[A[i]]-1) << endl;
  }
  
}