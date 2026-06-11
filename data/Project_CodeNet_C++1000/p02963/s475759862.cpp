#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000000;

int main(){
	long long s;
	cin>>s;

	cout<<0<<" "<<0<<" "<<inf<<" "<<1<<" "<<(inf-s%inf)%inf<<" "<<(s+(inf-s%inf)%inf)/inf<<endl;

	return 0;
}
