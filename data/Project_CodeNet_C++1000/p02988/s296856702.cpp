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
	int n;
	int p[20];
	cin >> n;
	REP(i,n) cin >> p[i];
	
	int ans=0;
	for(int i=1; i<n-1; i++){
		if(p[i-1]<p[i] && p[i]<p[i+1]) ans++;
		if(p[i-1]>p[i] && p[i]>p[i+1]) ans++;
	}
	
	cout << ans << endl;
	
	
	
	
	return 0;
}