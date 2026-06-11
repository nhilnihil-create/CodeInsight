#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int n; cin>>n;
	int k=n%1000;
	if(k){
		cout<<1000-k<<endl;
	}else{
		cout<<0<<endl;
	}
}