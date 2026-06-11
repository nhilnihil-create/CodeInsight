#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip> 
#include <cstring>
#include <queue>
#include <stack> 
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int n,k,c;
string s;
int l[200010];
int r[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k >> c >> s;
	int cnt = 1;
	for(int i = 0;i < n && cnt <= k;i++){
		if(s[i] == 'o'){
			l[i] = cnt++;
			i += c;
		}else{
			continue;
		}
	}
	cnt--;
	for(int i = n - 1;i >= 0 && cnt >= 1;i--){
		if(s[i] == 'o'){
			r[i] = cnt--;
			i -= c;
		}else{
			continue;
		}
	}
	for(int i = 0;i < n;i++){
		if(l[i] != 0 && r[i] != 0 && l[i] == r[i]){
			cout << i + 1 << endl;
		}
	}
	return 0;
}