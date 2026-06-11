#include<iostream>
#include <math.h>
using namespace std;

int N;

int main(){
    cin >> N;

    int X = double(N) / 1.08;

    int X1 = floor(X * 1.08);

    if (X1 == N){
        // cout << N << endl;
        cout << X << endl;
        // cout << X1 << endl;
        return 0;
    }
    else{
        X++;
        X1 = floor(X * 1.08);
        if (X1 == N)
        {
            cout << X << endl;
            // cout << X1 << endl;
            return 0;
        }
        else{
            // cout << X << endl;
            // cout << X1 << endl;
            cout << ":(" << endl;
        }
    }
}