#include <iostream>
using namespace std;

int main() {
    int N ;
    cin >> N ; //1 ≤ N ≤ 100
    if (N % 2 == 0 ) cout << int(N / 2) <<endl;
    else cout << int((N / 2) + 1) << endl;
	return 0;
}