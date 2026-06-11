#include <bits/stdc++.h>
using namespace std;
long long f(long long k){
	return (k*(k-1))/2;
}
int main(){
  long long n;
  long long now=0;
  cin>>n;
  vector<long long> p(n,0);
  long long a[n];
  for(int i=0;i<n;i++){
  	cin>>a[i];
    a[i]--;
    p[a[i]]++;
  }
  for(int i=0;i<n;i++){
  	now+=f(p[i]);
  }
  for(int i=0;i<n;i++){
  	long long k=now;
    k=k-f(p[a[i]])+f(p[a[i]]-1);
    cout<<k<<endl;
  }
}
