#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip>
#include <stack>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e12, cnt;

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll d=c-a-b;
	if(4*a*b<d*d && d>0){
		cout<<"Yes";
	}
	else cout<<"No";
}