#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>

using namespace std;

#define INF 1000000007
#define LINF 1000000000000000007

typedef long long i64;
typedef pair<i64,i64> P;


i64 n, a[101010];

int main(){
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ans = (ans ^ a[i]);
	}
	
	if(ans == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
