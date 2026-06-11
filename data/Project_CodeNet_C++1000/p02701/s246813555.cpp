#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
#include<set>
using namespace std;
 
#define PI 3.14159265358979323846264338327950L

int main() {
	int N;
	set<string> s;

	cin >> N;
	for (int ii = 0; ii < N; ii++) {
		string tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	cout << s.size() << endl;
}