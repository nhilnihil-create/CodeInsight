#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N % 1000 != 0){
        cout << (N / 1000 + 1 ) * 1000- N << endl;
    }
    else{
        cout << "0" << endl;
    }
}