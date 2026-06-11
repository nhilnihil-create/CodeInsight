#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	string a,b;
	int sum=0;
	cin>>a>>b;
	for (int i=0;i<3;i++){
		if(a[i]==b[i])
			sum+=1;
	}
	cout<<sum;
}