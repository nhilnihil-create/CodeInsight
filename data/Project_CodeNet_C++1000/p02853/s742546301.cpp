#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

int main(){
	
	vector<long> a(300,0);
	a[0]=300000;
	a[1]=200000;
	a[2]=100000;
	long bonus=400000,sum=0;
	
	int x,y;
	cin >> x >> y;
	sum+=a[x-1]+a[y-1];
	if(x==1&&y==1)sum+=bonus;
	
	cout << sum << endl;
	
	return 0;
}
