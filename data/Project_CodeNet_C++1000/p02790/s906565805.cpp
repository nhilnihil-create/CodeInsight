#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int a,b;
	cin>>a>>b;
	if(a>=b){
		rep(i,a){
			cout<<b;
		}
		
	}else{
		rep(i,b){
			cout<<a;
		}
	}
	cout<<endl;
}