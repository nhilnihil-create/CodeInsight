#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int A;
    for (int i = 0; i < N; i++) {
        A += 1000;
        if (N <= A) {
            break;
        }
    }
    cout << A - N;
}