#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int outlet = 1;
    int sumA = 0;

    while(outlet < B){
        outlet--;
        outlet += A;
        sumA++;
    }

    cout << sumA << endl;
}