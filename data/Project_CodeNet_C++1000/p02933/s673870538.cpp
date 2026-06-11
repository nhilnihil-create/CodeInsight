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
	int a;
	string s;
	cin >> a >> s;
	
	if(a>=3200) cout << s << endl;
	else cout << "red\n";
	
	return 0;
}