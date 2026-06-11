#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000

int main(){
	int n,l;cin>>n>>l;

	int all=0,MIN=INF,key;
	for(int i=1;i<=n;i++){
		all+=(l+i-1);
		if(MIN>abs(l+i-1)){
			MIN=abs(l+i-1);
			key=l+i-1;
		}
	}

	cout<<all-key<<endl;
	return 0;
}