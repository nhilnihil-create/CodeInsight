#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define vint vector<int>


int main(){
	int n;
	cin >> n;
	vint a(n);
	REP(i,n) cin >> a[i];
	
	int index=1;
	int ans=0;
	REP(i,n){
		if(a[i] != index){
			ans++;
		}else{
			index++;
		}
	}
	
	if(ans==n) cout << "-1\n";
	else cout << ans << endl;
	
	return 0;
}