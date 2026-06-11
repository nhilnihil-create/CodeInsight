#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    int remainder;
    bool lucky = false;

    cin >> N;
    rep(i, 3){
        remainder = N % 10;
        if (remainder == 7){
            lucky = true;
            break;
        }
        N /= 10;
    }

    if (lucky){
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}