#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std; 
ll N = pow(10,5);
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	int x,y;cin>>x>>y;
	ll sum=0;
	if(x<4){
		sum += (4-x)*N;
	}
	if(y<4){
		sum += (4-y)*N;
	}
	if(x==1 && y==1){
		sum += 4*N;
	}
	cout<<sum<<endl;
}