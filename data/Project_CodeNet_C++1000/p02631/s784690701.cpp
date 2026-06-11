#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std;

int main(){
  long long n;
  cin>>n;
  long long xorv=0;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
	xorv^=v[i];
  }
  for(int i=0;i<n;i++){
    v[i]=xorv^v[i];
	cout<<v[i]<<' ';
  }
  
  return 0;
}
