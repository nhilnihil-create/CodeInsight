#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin >> n;
  
   int ans[n];
   int a[n];
    for(int i=0;i<=n;i++){
	 ans[i]=0;
   	 a[i]=0;
  }

  
  for(int i=0;i<n;i++){
    cin>>a[i];
    ans[a[i]]++;
  }

	for(int k=1;k<=n;k++){
    	cout<<ans[k]<<endl;
    }
  
  
  
}