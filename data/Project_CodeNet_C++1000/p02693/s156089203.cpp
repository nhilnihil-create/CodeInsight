#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	for (int i=0;i<1000;i++){
		if (b<=a*i&&a*i<=c){
			cout<<"OK"<<endl;
			return 0;
		}
	}
	cout<<"NG"<<endl;
	return 0;
}