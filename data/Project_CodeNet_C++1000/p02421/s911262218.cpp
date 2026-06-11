#include <bits/stdc++.h>
using namespace std;

int main(void){
	string s1,s2;
	int n,p1,p2;
	cin >> n;
	p1 = 0;
	p2 = 0;
	for(int i = 0; i < n;i++){
		cin >> s1 >> s2;
		if(s1.compare(s2) == 0){
			p1++;
			p2++;
		}else if(s1.compare(s2) < 0){
			p2 += 3;
		}else {
			p1 += 3;
		}
	}
	cout << p1 << " " << p2 << endl;
}
