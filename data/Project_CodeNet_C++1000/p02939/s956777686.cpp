#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	string prev;
	prev = s[0];
	int count = 1;
	string current="";
	for(int i=1;i<(int) s.length(); i++){
		current += s[i];
		if (current != prev) {
			count++;
			prev = current;
			current = "";
		}
	}
	cout << count;
		
	
 }
