#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    if (A == 1){
        cout << B << endl;
        return 0;
    }
    int cnt1(B-(A-1)), cnt2(B+1);
    while (cnt1 < B){
        cout << cnt1 << " ";
        cnt1++;
    }
    cout << B << " ";
    while (cnt2 < B+A-1){
        cout << cnt2 << " ";
        cnt2++;
    }
    cout << cnt2 << endl;
    return 0;
}
