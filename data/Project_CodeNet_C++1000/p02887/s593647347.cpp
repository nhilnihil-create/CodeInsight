#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int n;
	cin>>n;
	int ans=1;
	char hoge;
	cin>>hoge;
	fori(n-1){
		char s;
		cin>>s;
		if(s!=hoge){
			++ans;
		}
		hoge=s;
	}
	cout<<ans;
}