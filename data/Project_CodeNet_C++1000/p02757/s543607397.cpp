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
int n,p;
ll temp,res;
int vis[2000005];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p >> s;
	int d = 1;
	vis[0] = 1;
	if(p == 2 || p == 5){
		for(int i = 0;i < s.length();i++){
			if((s[i] - '0') % p == 0 ){
				res += (i + 1);
			}
		}
	}else{
		for(int i = s.length() - 1;i >= 0;i--){
			temp = (((s[i] - '0') * d) % p + temp % p) % p;
			res += vis[temp];
			vis[temp]++;
			d = d * 10 % p;
		}
	}
	cout << res << endl;
	return 0;
}