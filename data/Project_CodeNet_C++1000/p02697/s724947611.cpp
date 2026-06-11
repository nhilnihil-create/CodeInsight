#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int n,m;cin>>n>>m;
	int a=m/2,b=m-m/2;
	rep(i,a){
		cout<<i+1<<' '<<(2*a+1)-i-1+1<<endl;
	}
	rep(i,b){
		cout<<i+2*a+2<<' '<<2*b-i-1+2*a+2<<endl;
	}
}