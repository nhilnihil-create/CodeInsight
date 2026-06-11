#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
void solve(){
	int n;
	cin>>n;
	int pr[1000001]={0};
	pr[0]=1;
	pr[1]=1;
	for(int i=2;i*i<=1000000;i++){
		if(!pr[i]){
			for(int j=i*i;j<1000001;j+=i){
				pr[j]=1;
			}	
		}
	}
	for(int i=n;i;i++){
		if(!pr[i]){
			cout<<i<<endl;
			break;
		}
	}
}

int main(){
    int t=1;
	//cin>>t;
    while(t--)
        solve();
}
