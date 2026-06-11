//dwango6_a.cpp
//Sat Feb 29 09:01:57 2020

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
using namespace std;
using ll=long long;
typedef pair<string,int> P;

int main(){
	int n;
	cin >> n;

	vector<P> list;
	for (int i=0;i<n;i++){
		string s;
		int t;
		cin >> s >> t;
		list.push_back(P(s,t));
	}

	string x;
	cin >> x;

	int flag = 0;
	int ans = 0;
	for (int i=0;i<n;i++){
		if (list[i].first==x){
			flag = 1;
		}else if (flag){
			ans += list[i].second;
		}
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}