//abc155_e.cpp
//Fri May 29 21:22:38 2020

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
	string s;
	cin >> s;

	int keta[s.length()+1];
	keta[0] = 0;
	for (int i=0;i<s.length();i++){
		keta[i+1] = int(s[i]-'0');
	}

	ll pay[11];
	pay[0] = 0;
	pay[1] = 1;
	pay[2] = 2;
	pay[3] = 3;
	pay[4] = 4;
	pay[5] = 5;
	pay[6] = 4;
	pay[7] = 3;
	pay[8] = 2;
	pay[9] = 1;
	pay[10] = 0;

	ll ans = 0;
	ll ketaagari = 0;
	for (int i=s.length();i>0;i--){
		if (keta[i]>=6){
			ans += pay[keta[i]];
			keta[i-1]++;
		}else if (keta[i]==5){
			if (keta[i-1]<=4){
				ans += pay[keta[i]];
			}else {
				ans += pay[keta[i]];
				keta[i-1]++;
			}
		}else{
			ans += pay[keta[i]];
		}
	}
	if (keta[0]==1){
		ans++;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}