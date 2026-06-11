#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n;
	cin>>n;
	vector<int> box(n+1);
	vector<int> ball(n+1,0);
	queue<int> que;
	for(int i=0;i<n;i++) cin>>box.at(i+1);
	int ans=0;

	for(int i=n;i>0;i--){
		int cnt=0;
		for(int j=i;j<=n;j+=i){
			if(ball.at(j)==1) cnt++;
		}
		if(cnt%2!=box.at(i)){
			ball.at(i)++;
			ans++;
			que.push(i);
		}
	}

	cout<<ans<<endl;
	while(!que.empty()){
		cout<<que.front();
		que.pop();
		if(!que.empty()) cout<<" ";
		else cout<<endl;
	}

	return 0;
}
