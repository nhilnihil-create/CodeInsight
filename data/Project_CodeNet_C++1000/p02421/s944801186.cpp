#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 0;
	int b = 0;
	for(int i=0;i<n;i++){
		string c,d;
		cin >> c >> d;
		int e = min(c.length(),d.length());
		bool w = true;
		for(int j=0;j<e;j++){
			if     (c[j]<d[j]){ w = false; a += 3; break; }
			else if(c[j]>d[j]){ w = false; b += 3; break; }
		}
		if(w){
			if     (c.length()<d.length()) a += 3;
			else if(c.length()>d.length()) b += 3; 
			else   { a++; b++; }
		}
	}
	cout << b << " " << a << endl;
}