#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
	int a, b;
	cin >> a >> b;
	cout << a / b << " " << a%b << " " << setiosflags(ios::fixed)<<setprecision(15)<< ((double)a / (double)b) << endl;
}