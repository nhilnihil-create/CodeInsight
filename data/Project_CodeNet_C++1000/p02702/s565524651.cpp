#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
using namespace std;

#define int long long
int cnt[2020];

int32_t main() {
	
 	string s;
 	
    cin>>s;
   
	reverse(s.begin(),s.end());
	
	int ans=0;
	
	int p = 1;
	
	int total =0;
	
	for(int i=0 ;i<s.length(); i++){
		
		cnt[total]++;
		
		total += ( ( s[i] - '0') * p);
		
		total %= 2019;
		
		ans += cnt[total];
		
		p = p* 10 % 2019;
		
	}

	cout << ans << endl;
	
}