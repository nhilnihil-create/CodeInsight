#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ret return
using namespace std;
int main() {
	//crane has two
	//turtle has four
	int x,y;
	cin>>x>>y;
	bool ok=0;
	for(int i=x;i>=0;i--) {
		int j=x-i;
		if(i*2+j*4==y)
			ok=1;
		
	}
	if(ok)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	
	ret 0;
}


