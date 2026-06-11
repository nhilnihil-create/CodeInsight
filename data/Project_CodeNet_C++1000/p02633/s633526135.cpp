#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	for(int i=1;i<=360;i++){
		if(x*i%360==0){
			cout<<i<<endl;
			return 0;
		}
	}
}