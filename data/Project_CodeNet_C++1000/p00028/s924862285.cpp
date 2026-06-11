#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
 
using namespace std;
 
const double eps=1e-10;
 
int main()
{
	int c[101]={0};
	int fre=0;

	int d;
	while(cin>>d){
		c[d]++;
		fre=max(fre,c[d]);
	}

	for(int i=1;i<=100;i++){
		if(c[i]==fre) cout<<i<<endl;
	}


	return 0;
}