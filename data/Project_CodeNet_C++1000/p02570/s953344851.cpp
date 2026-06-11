#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
	int d,t,s;
	cin >> d >> t >> s;
	double time=double(d)/double(s);
	if(time<=double(t)){
		cout << "Yes";
	}
	else cout << "No";
	return 0;
}
