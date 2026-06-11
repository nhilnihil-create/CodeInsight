#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string m;
		int a,b;
		cin >> m >> a >> b;
		if(m=="print") cout << s.substr(a,b-a+1) << endl;
		else if(m=="reverse"){
			string t;
			for(int j=0;j<a;j++) t += s[j];
			for(int j=b;j>=a;j--) t += s[j];
			for(int j=b+1;j<s.length();j++) t += s[j];
			s = t;
		}
		else if(m=="replace"){
			string p,t;
			cin >> p;
			t = s.substr(0,a) + p + s.substr(b+1,s.length()-b+1);
			s = t;
		}
	}
}