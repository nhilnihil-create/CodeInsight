#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){
	
	long long a;
	string b;
	cin >> a >> b;
	
	int bn = 0;
	for(int i = 0; i < b.size(); i++){
		if(b[i] == '.')continue;
		bn += b[i] - '0';
		bn *= 10;
	}
	bn /= 10;
	long long ans = a*bn;
	ans /= 100;
	cout << ans << endl;
	
	return 0;
}
 