#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){
	vector<int> a(4);
	for(int i=0;i<4;i++)cin >> a[i];
	if(a[0]==a[2])cout << 0 << endl;
	else cout << 1 << endl;
	return 0;
}
