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
	int a,b,c;
	cin >> a >> b >> c;

	if(a >= b+c) cout << "0\n";
	else cout << c - (a-b);
	
	
	
	
	
	
	
	
	return 0;
}