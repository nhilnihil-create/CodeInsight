#include<iostream>
using namespace std;
int a[105];

int main(){
	int n;
	int hasil=0;
	cin>>n;
	int x=1;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		if(a[i]%2==1&&x%2==1)hasil++;
		x++;
	}

	cout<<hasil<<endl;
	
}