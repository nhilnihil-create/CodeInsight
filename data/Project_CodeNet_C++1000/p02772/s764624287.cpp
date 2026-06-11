#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  	vector<int> a(110);
  	rep(i,n){
    	cin>>a[i];
    }
  
  bool dame=false;
  
  rep(j,n){
  	if(a[j]%2==0&&a[j]%3!=0&&a[j]%5!=0){
    	dame=true;
    }
  }
  
  if(dame){
  	cout<<"DENIED"<<endl;
  }
  
  else{
  	cout<<"APPROVED"<<endl;
  }

}