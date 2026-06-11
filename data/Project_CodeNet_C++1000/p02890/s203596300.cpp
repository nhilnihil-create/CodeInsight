#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <stdlib.h>
using namespace std;
typedef long long int lld;
typedef long double ld;
int n;
int arr[333333];
int vis[333333],vis2[333333];
vector<int> v;
int main(void){
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	sort(arr,arr+n);
	int tmp = 1;
	for(int e=1;e<n;e++){
		if(arr[e]!=arr[e-1]){
			v.push_back(tmp);
			tmp = 1;
		}else tmp++;
	}
	int lm = 0;
	v.push_back(tmp);
	for(int e=0;e<v.size();e++) lm = max(lm,v[e]);
	for(int e=0;e<v.size();e++) vis[v[e]]++;
	for(int len=1;len<=n;len++){
		if(v.size()<len){
			printf("0\n");
			continue;
		}
		for(int p=0;p<=lm;p++) vis2[p] = vis[p];
		int lmm = lm,ans=0;
		while(true){
			int tot = len,nlmm=0;
			vector<pair<int,int> > v2;
			for(int p=lmm;p>=1;p--){
				if(vis2[p]==0) continue;
				if(vis2[p]>=tot){
					v2.push_back(make_pair(p-1,tot));
					v2.push_back(make_pair(p,-tot));
					tot = 0;
					break;
				}else{
					v2.push_back(make_pair(p-1,vis2[p]));
					v2.push_back(make_pair(p,-vis2[p]));
					tot -= vis2[p];
				}
			}
			if(tot) break;
			ans++;
			for(int e=0;e<v2.size();e++){
				vis2[v2[e].first] += v2[e].second;
			}
			for(int p=lmm;p>=1;p--) if(vis2[p]){
				lmm = p;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}