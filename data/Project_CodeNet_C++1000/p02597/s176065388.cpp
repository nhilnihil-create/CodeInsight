#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[223456];
int n,k;
bool check(int t){
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=(int)ceil(a[i]*1.0/t)-1;
	}
	if(sum>k)return false;
	return true;
}
string s;
int main(){
	int n;
	cin>>n;
	int sum=0,cnt=0;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='W')sum++;
	}
	for(int i=n-sum;i<n;i++)if(s[i]=='W')cnt++;
	cout<<sum-cnt<<endl;
} 
