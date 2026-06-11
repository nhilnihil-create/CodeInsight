#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,i,j;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	for(i=1; ; i++){
		if((a*i)%360==0){
			cout<<i;
			return 0;
		}
	}
	return 0;
}