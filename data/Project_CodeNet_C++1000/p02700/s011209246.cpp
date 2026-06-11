#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    string takahashi;
    while(true){
        C -= B;
        if(C <= 0){
            takahashi = "Yes";
            break;
        } 
        A -= D;
        if(A <= 0){
            takahashi = "No";
            break;
        }
    }
    cout << takahashi << endl;
}