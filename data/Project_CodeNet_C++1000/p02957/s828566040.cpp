#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>
#include <iomanip>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;


int main(){
	ll a,b;
	cin>>a>>b;
	ans =abs(a-b);
	if(ans%2==0){
		ans /=2;
		cout<<max(a,b)-ans;
	}
	else cout<<"IMPOSSIBLE"<<endl;
}
