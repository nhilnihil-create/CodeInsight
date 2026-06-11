#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;



int main(){
	string s,t;
	cin>>s>>t;
	for(int i=0; i<3; i++){
		if(s[i]==t[i]) ans++;
	}
	cout<<ans;
}