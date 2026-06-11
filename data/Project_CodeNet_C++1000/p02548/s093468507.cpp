// C - A x B + C
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n; --n;
	int c = 0;
	for(int x=1; x*x<=n; ++x) c += (n / x - x) * 2 + 1;
	cout<< c <<endl;
}
