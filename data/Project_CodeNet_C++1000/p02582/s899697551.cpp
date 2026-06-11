#include <bits/stdc++.h>
using namespace std;

int main(){
	
char s[3];
cin >> s;
int count = 0;

for(int i=0; i<3; i++){
	if(s[i] == 'R') {count++; }
}

if(count == 2){

if(s[0] == 'R' && s[1] == 'R') { cout << '2'; }

if(s[1] == 'R' && s[2] == 'R') { cout << '2'; }


if(s[0] == 'R' && s[2] == 'R') { cout << '1'; }
}

if(count == 1) {cout << '1';}
if(count == 0) {cout << '0';}
if(count == 3) {cout << '3';}



return 0;
	
}
