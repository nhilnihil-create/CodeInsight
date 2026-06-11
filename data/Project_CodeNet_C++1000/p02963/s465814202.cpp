#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
#include<cmath>
const int v = 1000000000;
using namespace std;
int main() {
	long long int s;
    cin >> s;
	int x = (v - s % v) % v;
	int y = (s + x) / v;
	cout << "0 0 1000000000 1 " << x << " " << y << endl;
    return 0;
}