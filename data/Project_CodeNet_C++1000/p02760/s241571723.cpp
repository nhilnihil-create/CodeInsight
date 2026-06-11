#include <iostream>
#include <vector>

using namespace std;

int main(){
    int A[9];
    int n, b[10];
    bool card[9];
    for(int i = 0; i < 9; i++) {
        card[i] = false;
        cin >> A[i];
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            if(A[j] == b[i]) {
                card[j] = true;
            }
        }
    }

    bool bingo = false;
    for(int i = 0; i < 3; i++) {
        if(card[3*i] && card[3*i+1] && card[3*i+2]) {
            bingo = true;
        }
        if(card[0+i] && card[3+i] && card[6+i]) {
            bingo = true;
        }
    }
    if(card[0] && card[4] && card[8]) {
        bingo = true;
    }
    if(card[2] && card[4] && card[6]) {
        bingo = true;
    }

    if(bingo) {
        cout << "Yes"<< endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
