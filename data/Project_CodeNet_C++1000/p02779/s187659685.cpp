#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n); i++)
using namespace std;
typedef long long int ll;
const int mod = 1000000007;
bool a[1000000001]={};
int main(){
	int n;
	cin>>n;
	rep(i,n){ 
		int k;
		cin>>k;
		if(a[k]){ 
			cout<<"NO"<<endl;
			return 0;
		}
		else a[k]=true;
	}
		
	
	cout<<"YES"<<endl;
	return 0;
}
