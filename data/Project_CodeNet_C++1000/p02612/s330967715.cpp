#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N % 1000 == 0){
        cout << 0 << endl;
    }
    else{
        int pay = (N / 1000 + 1) * 1000;

        cout << pay - N << endl;
    }
}