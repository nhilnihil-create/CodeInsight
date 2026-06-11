#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <limits.h>
using namespace std;
int N;
string s;
int r,w;
int ans=10000000;
int tmp=0;
int main(){
	cin >> N;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='R')r++;
		else w++;
	}
	int nr=0,nw=0;
	int cr=0,cw=0;
	ans = min(ans,r);
	ans = min(ans,w);
	for(int i=0;i<s.length();i++){
		if(s[i]=='R')nr++;
		else nw++;

		cw=nw;
		cr=r-nr;
		//ans = min(ans,max(cr,cw));
		ans = min(ans,max(r-nr,nw));
	}
	cout << ans << endl;
	return 0;
}
