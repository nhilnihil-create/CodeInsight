#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int N,a[100],b[100];
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i]>>b[i];
	for(int i=2;i<N;i++){
		if(a[i-2]==b[i-2] && a[i-1]==b[i-1] && a[i]==b[i]){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}