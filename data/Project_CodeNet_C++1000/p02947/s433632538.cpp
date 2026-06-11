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

ll combination2(ll num){
	if(num <= 1) return 0;
	return num*(num-1)/2;
}

int main()
{
	int n;
	cin>>n;
	map<string,int> strList;
	rep(i,n){
		string str;
		cin>>str;
		vector<int> localVec(str.size());
		for(int i = 0; i < str.size(); i++){
			localVec[i] = (int)str[i];
		}
		sort(localVec.begin(),localVec.end());
		for(int i = 0; i < str.size(); i++){
			str[i] = (char)localVec[i];
		}
		if( strList.count(str) == 0){
			strList.insert(make_pair(str,1));
		}else{
			strList[str] += 1;
		}
	}
	ll ans = 0;
	for(auto iter = strList.begin();iter != strList.end(); iter++){
		ll num = iter->second;
		ans += combination2(num);
	}
	cout<<ans<<endl;
	return 0;
}
