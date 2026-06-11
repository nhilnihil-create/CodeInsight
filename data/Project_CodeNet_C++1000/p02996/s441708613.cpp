#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >a;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.push_back(make_pair(y,x));
	}
	sort(a.begin(),a.end());\
	int count=0;
	for(int i=0;i<n;i++){
		count+=a[i].second;
		if(count>a[i].first){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
    return 0;
}

