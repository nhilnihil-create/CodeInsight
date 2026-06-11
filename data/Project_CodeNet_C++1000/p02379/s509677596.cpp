#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
		
int main(void){
	double x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	cout.precision(12);
	cout<<fixed<<hypot(x2-x1,y2-y1)<<endl;
	return 0;
}