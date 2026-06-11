#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;

#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
#define REP(i,n) for(long long int i=0;i<(n);i++)

#define PI 3.14159265358479

int main(){
	REP(i, 9){
		REP(j, 9){
			cout << i + 1 << "x" << j + 1 << "=" << (i + 1)*(j + 1) << "\n";
		}
	}
	return 0;
}