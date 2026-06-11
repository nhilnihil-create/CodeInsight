#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#define L(_i,_N) for(int _i=1;_i<=_N;_i++)
typedef long long int lli;
using namespace std;

int main() {
	L(i,9)
		L(j,9)
			cout << i << "x" << j << "=" << i*j << endl;
	return 0;
}