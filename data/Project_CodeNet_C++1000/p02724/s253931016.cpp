#include <bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin >> X;

    int happy = 0;
    happy += 1000 * (X / 500);
    X %= 500;

    int i = 0;
    while(X > 5){
        X -= 5;
        i++;
    }

    happy += 5 * i;
    cout << happy << endl;
}