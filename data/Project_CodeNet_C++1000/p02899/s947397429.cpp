#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main() {
	int n;
    cin>>n;
    
  	vector <int> a(n);
  	int t[n];
  	rep(i,n){
      cin>>a[i];
    }
  
   vector<int> rev(n);
  for(int i=0;i<n;i++)rev[a[i]-1]=i+1;
  for(int i=0;i<n;i++)cout<<rev[i]<<endl;
    	
  
}