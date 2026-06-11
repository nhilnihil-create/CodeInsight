#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	map<int,int> m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		m[x]++;
	}
	if(n%3!=0){
		if(m.size()==1&&m.begin() -> first == 0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	else{
		vector<int> v;
		for(auto it:m)
			if(it.second %(n/3) !=0){
				cout<<"No"<<endl;
				return 0;
			}
			else{
				for(int i=0;i<it.second/(n/3);i++)
					v.emplace_back(it.first);
			}
		if(v[0]^v[1]^v[2])
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;	
	}
}
