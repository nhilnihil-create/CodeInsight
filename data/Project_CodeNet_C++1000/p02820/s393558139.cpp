#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;
const int inf = 99999999;

using namespace std;

const ll mod = 1e9 + 7;

int main(){
	int n , k;
	cin >> n >> k;
	int r,s,p;
	cin >> r >> s >> p;
	string t;
	cin >> t;
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(t[i] == 'r'){
			if(i - k >= 0 && t[i - k] == 'r'){
				t[i] = 'x';
				continue;
			}
			ans += p;
		}else if(t[i] == 's'){
			if(i - k >= 0 && t[i - k] == 's'){
				t[i] = 'x';
				continue;
			}
			ans += r;
		}else{
			if(i - k >= 0 && t[i - k] == 'p'){
				t[i] = 'x';
				continue;
			}
			ans += s;
		}
	}
		
	cout << ans << endl;
	return 0;
}
 