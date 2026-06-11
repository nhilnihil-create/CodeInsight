#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000000;

int main(){
	long long n,k,s;
	cin>>n>>k>>s;

	for(int i=1;i<=n;i++){
		if(i<=k){
			cout<<s;
		}else{
			if(s==inf){
				cout<<1;
			}else{
				cout<<inf;
			}
		}

		if(i<n) cout<<" ";
		else cout<<endl;
	}

	return 0;
}
