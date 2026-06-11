#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>
#include <set>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int d,a;
	cin>>d;
	vector<int>c(27);
	vector<vector<int>> s(d+1, vector<int>(27));
	vector<int>t(d+1);
	vector<int>last(27);
	for(int i=0;i<=27;i++)last[i]=0;
	for(int i=1;i<=26;i++) cin>>c[i];
	for (int i = 1; i <= d; i++) {
	    for (int j = 1; j <= 26; j++) {
	      cin >> s.at(i).at(j);
	    //  cout<< s.at(i).at(j)<<endl;
	    }
	  }
	int tt,sum=0;
	for(int i=1;i<=d;i++){
		cin>>tt;
		sum+=s[i][tt];
		last[tt]=i;
		for(int j=1;j<=26;j++){
			sum-=c[j]*(i-last[j]);
		}
		cout<<sum<<endl;
	}

	return 0;
}
