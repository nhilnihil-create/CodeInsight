#include <iostream>
using namespace std;


int main(){
	long long int a, b, n;
  	cin>>a>>b>>n;
  	
  	long long int t=(b-1<n)? b-1:n;
  	long long int max=(a*t)/b;
  	
  
  	cout<<max<<endl;
}