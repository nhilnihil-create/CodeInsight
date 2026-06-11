#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
	ll n;
	cin>>n;
	vector<int>pos;
	for(ll i=2; i*i<=n; i++){
		int cnt=0;
		while(n%i==0){
			n/=i;
			cnt++;
		}
		if(cnt)
		 pos.push_back(cnt);
	}
	if(n>1)
	 pos.push_back(1);
	int ans=0;
	for(int i=0; i<pos.size(); i++){
		int num=pos[i];
		int cnt=0;
		int j=1;
		while(true){
			num=num-j;
			if(num<0)
			 break;
			cnt++;
			j++;
		}
		ans+=cnt;
	}
	cout<<ans;
	return 0;
	
}
