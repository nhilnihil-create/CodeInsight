
#include<bits/stdc++.h>

using namespace std;

int main() {
	//int x;
	//cin>>x;
	//x -= 400;
	//x /= 200;
	
	//cout<< 8 - x<<endl;
	
	int a, b, c, k;
	cin>>a>>b>>c>>k;
	
	while(b <= a) {
		b = 2*b;
		k--;
	}
	while(c <= b) {
		c *= 2;
		k--;
	}
	if(k >= 0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
