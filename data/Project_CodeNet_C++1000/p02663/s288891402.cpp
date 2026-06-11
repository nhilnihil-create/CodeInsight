#include <bits/stdc++.h>
using namespace std;

int main() {
	int H1, M1, H2, M2, K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    cout << (H2*60+M2)-(H1*60+M1)-K << endl;
}
