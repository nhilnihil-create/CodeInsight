#include<iostream>
#include<set>
using namespace std;

set<int>prime;
int main(){
	prime.insert(2);
	for(int i=3;i<500000;i++){
		for(int j=2;j*j<=i;j++){
			if(i%j==0)goto fail;
		}
		prime.insert(i);
		fail:;
	}
	
	int n;
	while(cin>>n && n){
		int ans=0;
		for(set<int>::iterator itr=prime.upper_bound(n);*itr<=n*2;itr++)ans++;
		cout<<ans<<endl;
	}
	
}