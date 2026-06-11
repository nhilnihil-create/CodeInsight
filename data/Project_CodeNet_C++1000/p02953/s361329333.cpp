#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N==1) {
        cout << "Yes" << endl;
        return 0;
    }

    int H[N];
    for (int i=0; i<N; i++) {
        cin >> H[i];
    }

    for (int i=N-1; i>0; i--) { 
        if (H[i-1] - H[i] > 1) {
            cout << "No" << endl;
            return 0;
        }
        if (H[i-1] - H[i] == 1) {
            H[i-1]--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}