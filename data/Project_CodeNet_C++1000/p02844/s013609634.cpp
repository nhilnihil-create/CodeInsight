//q006.cpp
//Sat Sep 19 16:39:00 2020

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
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;

	int l[n][10],r[n][10];
	rep(i,n)rep(j,10){
		l[i][j] = 0;
		r[i][j] = 0;
	}

	rep(i,n-1){
		l[i][s[i]-'0']++;
		rep(j,10) l[i+1][j] = l[i][j];
	}

	for(int i=n-1;i>0;i--){
		r[i][s[i]-'0']++;
		rep(j,10) r[i-1][j] = r[i][j];
	}

	set<int> ans;
	for(int i=1;i<n-1;i++){
		rep(j,10)rep(k,10){
			if (l[i-1][j]!=0 && r[i+1][k]!=0){
				ans.insert(j*100+k+(s[i]-'0')*10);
			}
		}
	}
	cout << ans.size() << endl;
//	printf("%.4f\n",ans);
}