#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define pc __builtin_popcount

int ar[100005];
map<int,int> mp;

int32_t main(){
	//freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		mp[ar[i]]++;
	}
	sort(ar+1,ar+n+1);
	/*cout<<mp.size()<<"\n";
	for(auto x: mp){
		cout<<(x.first)<<" "<<(x.second)<<"\n";
	}*/
	if(mp.size()==3 && ((n%3)==0)){
		if(mp[ar[1]]==mp[ar[n]] && mp[ar[1]]==mp[ar[(n+1)/2]]){
			if((ar[1]^ar[n])==(ar[(n+1)/2])){
				cout<<"Yes";
				return 0;
			}
		}
	}
	if(mp.size()==2){
		if(mp[ar[1]]==mp[ar[n]]/2 && ar[1]==0){
			cout<<"Yes";
			return 0;
		}

	}
	if(mp.size()==1){
		if(ar[1]==0){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}
