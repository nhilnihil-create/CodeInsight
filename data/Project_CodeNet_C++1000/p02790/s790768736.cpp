#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
int main() {
	char a[1000]="", b[1000]="";
	cin >> a[0] >> b[0];
	for (int i = 1; i < b[0]-'0'; i++) {
		a[i] = a[0];
	}
	for (int i = 1; i < a[0]-'0'; i++) {
		b[i] = b[0];
	}
	cout << min((string)a,(string) b) << endl;
		return 0;
	
}