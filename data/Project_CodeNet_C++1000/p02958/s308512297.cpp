#include<bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

int main(){
	int n;cin>>n;
	vector<int>vec(n);
	for(int i=0;i<n;i++)cin>>vec[i];
	vector<int>s=vec;
	sort(s.begin(),s.end());
	if(vec==s){
		cout<<"YES"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		vector<int>g=vec;
		swap(g[i],g[j]);
		if(g==s){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
