#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <cfloat>
using namespace std;
int main(){
	
	int n;
	
	while(cin>>n,n!=0){
	int A=0,B=0;
	vector<int>a(n);
	vector<int>b(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(a[i]>b[i])
			A+=a[i]+b[i];
		else if(b[i]>a[i])
			B+=a[i]+b[i];
		else{
			A+=a[i];
			B+=b[i];
		}
	}
	cout<<A<<" "<<B<<endl;
	}
}