#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int main(){
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		v.push_back(a);
	}
	int now=1;
	for(int i=0;i<v.size();i++){
		if(v[i]==now){
			now++;
		}
	}
	if(now==1){cout<<-1<<endl;}
	else{
		cout<<n-(now-1)<<endl;
	}
	return 0;
}
