#include<iostream>
using namespace std;

bool p[33];
int input;

int main(){
	fill(p, p+30, false);
	while(cin >> input) p[input-1] = true;
	for(int i=0; i < 30; i++) if(!p[i]) cout << i+1 << endl;
}