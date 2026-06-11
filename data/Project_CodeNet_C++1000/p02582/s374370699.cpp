#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int count = 0;
    for (int i = 0; i < S.size(); i++) if (S[i] == 'R') count++;
    if (count == 2) {
        if (S[1] == 'S') cout << count - 1 << endl;
        else cout << count << endl;
    }
    else cout << count << endl;
}
