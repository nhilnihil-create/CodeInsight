//abc146_f.cpp
//Fri Jun  5 22:06:06 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(s.begin(),s.end());
	int maxplace[n+1];
	fill(maxplace,maxplace+n+1,0);
	set<int> nums;
	for (int i=0;i<=min(m,n);i++){
		if (s[i]=='0'){
			nums.insert(i);
		}
	}

	for (int i=0;i<n;i++){
		int tmp = i+m+1;
		// cout << i << " " << tmp << endl;
		if (nums.size()==0){
			cout << -1 << endl;
			return 0;
		}
		if (s[i]=='1'){
			if (s[min(tmp,n)]=='0'){
				nums.insert(min(tmp,n));
			}
			continue;
		}
		auto itr = nums.rbegin();
		maxplace[i] = *itr;
		nums.erase(i);
		if (s[min(tmp,n)]=='0'){
			nums.insert(min(tmp,n));
		}
	}

	// cout << s << endl;
	// for (int i=0;i<n+1;i++){
	// 	cout << maxplace[i];
	// }
	// printf("\n");

	vector<int> ans;
	ans.push_back(0);
	int cur = 0;
	while (cur != n){
		if (maxplace[cur]==cur){
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(maxplace[cur]);
		cur = maxplace[cur];
	}

	for (int i=ans.size()-1;i>0;i--){
		cout << ans[i]-ans[i-1] << " ";
	}
	printf("\n");
//	printf("%.4f\n",ans);
}