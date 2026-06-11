#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;

int x, t;

int main(){
	cin>>x;
	if(x >= 400 && x <= 599)t = 8;
	if(x >= 600 && x <= 799)t = 7;
	if(x >= 800 && x <= 999)t = 6;
	if(x >= 1000 && x <= 1199)t = 5;
	if(x >= 1200 && x <= 1399)t = 4;
	if(x >= 1400 && x <= 1599)t = 3;
	if(x >= 1600 && x <= 1799)t = 2;
	if(x >= 1800 && x <= 1999)t = 1;
	cout<<t<<endl;
	return 0;
}
