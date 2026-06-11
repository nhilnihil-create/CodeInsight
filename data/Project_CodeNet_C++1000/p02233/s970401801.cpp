#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
int F[50];
int fib(int i){
	if(i == 0 || i == 1) return 1;

	if(F[i] != -1) return F[i];
	
	return F[i] = fib(i-1) + fib(i-2);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < 50;i++) F[i] = -1;
	cout << fib(n) << endl;
	return 0;
}