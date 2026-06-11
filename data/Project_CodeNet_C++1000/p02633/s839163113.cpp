#include<bits/stdc++.h>
using namespace std;
int main(void){
	int x;
	cin>>x;
	int i=1;
	while(true){
		if(360*i%x==0){
			break;
		}
		i++;
	}
	cout<<360*i/x;
}
