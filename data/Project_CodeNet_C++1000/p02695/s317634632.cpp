#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
int a[50];
int b[50];
int c[50];
int d[50];

int estimate(vector<int> numList,int q){
	int ans = 0;
	//cout<<numList.size()<<endl;
	for(int i = 0; i < q; i++){
		if( numList[b[i]-1] - numList[a[i]-1] == c[i]){
			ans += d[i];
		}
	}
	return ans;
}

int dfs(vector<int> numList,int n,int m,int q){
	if( numList.size() == n){
		return estimate(numList,q);
	}
	int last = numList.back();
	int ans = 0;
	for(int i = last; i <= m; i++){
		numList.push_back(i);
		ans = max(ans,dfs(numList,n,m,q));
		numList.pop_back();
	}
	return ans;
}

int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	rep(i,q){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	vector<int> numList;
	int ans = 0;
	for(int i = 1; i <= m; i++){
		//cout<<numList.size()<<endl;
		numList.push_back(i);
		ans = max(ans,dfs(numList,n,m,q));
		numList.pop_back();
	}
	cout<<ans<<endl;
	return 0;
}
