#include<bits/stdc++.h>

using namespace std;

int main(){
	int h,m,s1,s2;
	cin >> s1;
	h=s1/3600;
	m=(s1-h*3600)/60;
	s2=(s1-h*3600)-60*m;
	cout << h << ":" << m << ":" << s2 << endl;
	return 0;
}