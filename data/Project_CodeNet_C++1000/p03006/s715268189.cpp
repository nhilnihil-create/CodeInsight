#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main(){
	int n;	cin>>n;
	vector<P> balls(n);	for(int i=0;i<n;i++)cin>>balls[i].first>>balls[i].second;

	int ans=n;
	for(int I=0;I<n;I++){
		for(int J=0;J<n;J++){
			if(I==J)continue;

			int p=balls[I].first-balls[J].first;
			int q=balls[I].second-balls[J].second;

			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j)continue;

					if(balls[i].first-balls[j].first==p && balls[i].second-balls[j].second==q){
						cnt++;
						break;
					}
				}
			}

			ans=min(n-cnt,ans);
		}
	}
	cout<<ans<<endl;

	return 0;
}
