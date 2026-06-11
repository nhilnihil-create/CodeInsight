#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;


int main() {
	int n;
	cin>>n;
	vector<pair<int,int>>robot(n);
	for(int i=0;i<n;i++){
		int x,l;
		cin>>x>>l;
		robot[i].first=x+l;
		robot[i].second=x-l;
	}
	sort(robot.begin(),robot.end());
	int ans=0;
	int tmp=-1e9-1;
	for(int i=0;i<n;i++){
		if(tmp>robot[i].second)continue;
		ans++;
		tmp=robot[i].first;
	}
	cout<<ans<<endl;
	return 0;
}