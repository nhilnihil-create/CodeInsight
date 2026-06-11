#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;

int main(){

	int n;
	int m=250000;
	bool flag[300000];
	memset(flag, 1, sizeof(flag));
	flag[0]=0, flag[1]=0;
	for(int i=2; i*i<=m; i++){
		if(flag[i]){
			for(int j=2; i*j<=m; j++){
				flag[i*j]=0;
			}
		}
	}
	while(cin >> n && n){
		int ans=0;
		for(int i=n+1; i<=2*n; i++){
			if(flag[i]){
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

