#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s[n],t;
	vector<int> d(n,0);
	
	for(int i=0;i<n;i++){
		cin >> s[i] >> d[i];	
	}
	
	cin >> t;
	
	int slp,sum=0;
	bool flg=false;
	for(slp=0;slp<n;slp++){
		if(flg){
			sum+=d[slp];
		}
		if(t==s[slp]){
			flg=true;
		}
	}
	cout << sum << endl;
	return 0;
}
