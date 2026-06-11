#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF  int(1e6+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

int main()
{
	long long int a, b,t;
	cin >> a >> b;
	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	long long int x,na=a,nb=b;
	while (nb) {
		x = nb;
		nb = na % nb;
		na = x;
	}
	cout << a * b / na << endl;
}
