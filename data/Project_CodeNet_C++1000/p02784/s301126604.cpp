#include <iostream>
using namespace std;

int main()
{
    int H, N;
    cin >> H >> N;
    int sum = 0;
    int A;
    for(int i = 0; i < N; i++) {
        cin >> A;
        sum += A;
    }
    if(sum >= H) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}