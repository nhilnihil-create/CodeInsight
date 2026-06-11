#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

int a[1000]={0};

int main(){
	int x,n;
	cin>>x>>n;
	int re;
	for(int i=0;i<n;i++){
	cin>>re;
	a[re]++;	
	}
	
	int ans,res,ans1=inf,res1;
	for(int i=x;i<=101;i++){
		if(a[i]==0){
		ans = i - x;
		res = i;
		break;	
		} 
	}
	for(int i=x-1;i>=0;i--){
		if(a[i]==0){
		ans1 = min(ans1,x - i);
		res1 = i;
		break;	
		}
	}
	if(ans < ans1) cout<<res<<endl;
	if(ans == ans1) cout<<res1<<endl;
	if(ans > ans1) cout<<res1<<endl;
	return 0;
}