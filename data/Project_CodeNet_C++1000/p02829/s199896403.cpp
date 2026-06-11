#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int b,c;
	cin>>b>>c;
	if(abs(b-c)==2)
	cout<<2;
	else if((b==1||b==2)&&(c==1||c==2))
	cout<<3;
	else
	cout<<1;
}
