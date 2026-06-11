#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b; 
    int counter = 0;
    int answer = 1;
    while (answer < b) {
        counter++;
        answer = answer + a;
        answer = answer - 1;
    }
    cout << counter;
}
