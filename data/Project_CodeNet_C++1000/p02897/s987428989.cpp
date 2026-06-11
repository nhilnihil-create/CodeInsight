#include <iostream>
using namespace std;

float N;
int numOdd;
float probs;

int main() {
    cin >> N;
    numOdd = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            numOdd++;
        }
    }
    probs = numOdd/N;
    cout << probs;
}