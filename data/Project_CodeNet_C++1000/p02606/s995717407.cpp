#include <bits/stdc++.h>

using namespace std;

int main() {
    int l;
    cin >> l;
    int r;
    cin >> r;
    int d;
    cin >> d;
    int output = 0;
    for (int i = l; i <= r; i++){
        if (i % d == 0){
            output++;
        }
    }
    cout << output;
	return 0;
}