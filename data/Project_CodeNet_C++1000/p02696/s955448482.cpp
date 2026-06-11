#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int64_t a,b,n;
	cin>>a>>b>>n;

	int64_t x=n;
	if(n>=b)n=b-1;
	cout << int64_t((a*n)/b);


	return 0;
}