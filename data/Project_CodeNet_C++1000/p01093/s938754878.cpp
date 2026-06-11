#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N=1e3*5;
const int INF=1e8;
int a[MAX_N];
int main(){
	int n;
	while(cin>>n && n!=0){
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int ans=INF;
		for(int i=0;i<n-1;i++){
			ans=min(ans,a[i+1]-a[i]);
		}
		cout<<ans<<endl;
	}
}