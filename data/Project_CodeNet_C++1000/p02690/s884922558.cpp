#include<bits/stdc++.h>
#define pb push_back
#define int long long int
using namespace std;
vector<int> bit(int x){
	vector<int> a;
	while(x){
		a.push_back(x%2);
		x /=2;
	}
	reverse(a.begin(), a.end());
	return a;
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int x; cin>>x;
	//cout<<x<<endl;
	map<int, int> m;
	for(int i=0; i<2001; i++){
		int y=i*i*i*i*i;
		//if(i==) cout<<y<<endl;
		m[y]=i;
		m[-1*y]= (-1*i);
	}
	for(auto i=m.begin(); i != m.end(); i++){
		if(m.find(x+i->first) != m.end()){
			cout<<m[x+i->first]<<" "<<i->second<<endl;
			break;
		}
	}
	
	
}
