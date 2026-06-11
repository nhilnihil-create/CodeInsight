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

int main(){
	int n;
	cin>>n;
	vector<int> numList(n);
	rep(i,n) cin>>numList[i];
	int ans = 0;
	for(int i = 1; i < n-1; i++){
		if( numList[i-1] < numList[i] && numList[i] < numList[i+1]){
			ans++;
		}else if( numList[i-1] > numList[i] && numList[i] > numList[i+1]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
