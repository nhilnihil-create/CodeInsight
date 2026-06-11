#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int h,w;
	cin>>h>>w;
	vector<string> grid(h);
	for(int i=0;i<h;i++) cin>>grid.at(i);

	struct m{
		int u=0;
		int d=0;
		int l=0;
		int r=0;
	};

	vector<vector<m>> dp(h+2,vector<m>(w+2));

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(grid.at(i-1).at(j-1)=='.'){
				dp.at(i).at(j).u=dp.at(i-1).at(j).u+1;
				dp.at(i).at(j).l=dp.at(i).at(j-1).l+1;
			}
		}
	}

	for(int i=h;i>0;i--){
		for(int j=w;j>0;j--){
			if(grid.at(i-1).at(j-1)=='.'){
				dp.at(i).at(j).d=dp.at(i+1).at(j).d+1;
				dp.at(i).at(j).r=dp.at(i).at(j+1).r+1;
			}
		}
	}

	int ans=0;

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int pre=0;

			pre+=dp.at(i).at(j).u+dp.at(i).at(j).d-1;
			pre+=dp.at(i).at(j).l+dp.at(i).at(j).r-2;

			ans=max(ans,pre);
		}
	}

	cout<<ans<<endl;

	return 0;
}
