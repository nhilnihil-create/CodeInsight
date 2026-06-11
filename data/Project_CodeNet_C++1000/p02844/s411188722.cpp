//q6.cpp
//Sat Aug  8 10:08:39 2020

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

	int mae[n][10],ushiro[n][10];
	rep(i,n){
		rep(j,10){
			mae[i][j] = 0;
			ushiro[i][j] = 0; 
		}
	}

	rep(i,n){
		if (i>0){
			rep(j,10){
				mae[i][j] = mae[i-1][j];
			}
		}
		mae[i][int(s[i]-'0')]++;
	}

	for (int i=n-1;i>=0;i--){
		if(i<n-1){
			rep(j,10){
				ushiro[i][j] = ushiro[i+1][j];
			}
		}
		ushiro[i][int(s[i]-'0')]++;
	}

	int count[1000];
	fill(count,count+1000,0);
	for (int i=1;i<n-1;i++){
		int center = int(s[i]-'0')*10;
		rep(j,10)rep(k,10){
			if (mae[i-1][j]!=0 && ushiro[i+1][k]!=0){
				int tmp = 100*j+center+k;
				count[tmp]++;
			}
		}
	}

	int ans = 0;
	rep(i,1000){
		if (count[i]!=0) ans++;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}