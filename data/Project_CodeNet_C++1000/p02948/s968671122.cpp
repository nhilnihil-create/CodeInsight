#include<iostream>
#include<iomanip>
#include<functional>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<set>
#include<queue>
#include<cmath>

using namespace std;
#define LL long long
#define mod 1000000007

int N,M,ans=0;
pair<int,int>AB[111111];
priority_queue<int>pq;

int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>AB[i].first>>AB[i].second;
	sort(AB,AB+N);
	AB[N].first=999999;
	int ok=0;
	for(int i=1;i<=M;i++){
		while(AB[ok].first<=i){
			pq.push(AB[ok].second);
			ok++;
		}
		if(pq.size()==0)continue;
		ans+=pq.top();
		pq.pop();
	}
	cout<<ans<<endl;
	return 0;
}

