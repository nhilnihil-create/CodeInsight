#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	string s;
	cin>>s;

	for(int i=0;i<(int)s.size();i++){
		if(s.at(i)=='?') s.at(i)='D';
	}

	cout<<s<<endl;

	return 0;
}
