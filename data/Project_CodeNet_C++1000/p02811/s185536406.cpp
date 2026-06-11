#include <iostream>
#include <string>
using namespace std;

int main() {
    int K , X ;
    cin >> K >> X ; // 1 ≤ K ≤ 100, 1 ≤ X ≤ 10^5
    int T = K * 500;
    if(T < X) cout << "No"<< endl;
    else cout << "Yes" <<endl;
	return 0;
}