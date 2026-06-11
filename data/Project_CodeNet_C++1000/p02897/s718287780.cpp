#include <iostream>
using namespace std;

int main() {
    int N ;
    cin >> N ; // 1 ≤ N ≤ 100
    double A = N - N/2 ;
    double B = N;
    cout << A/B << endl;
	return 0;
}