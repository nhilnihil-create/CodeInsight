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
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)



int main(){
	int n, l;
	cin >> n >> l;
	int ans=0;
	int index;
	if(l>=0) index = 0;
	else if(l <= -1*n) index = n-1;
	else index = n;
	
	REP(i,n){
		if(l + i == 0 || index == i) continue;
		ans += l+i;
	}
	
	cout << ans << endl;
	
	
	return 0;
}