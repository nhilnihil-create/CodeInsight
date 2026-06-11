#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A = N / 500; // "/" は切り捨ての割り算
    int B = (N - 500*A) / 5;
    cout << 1000*A+5*B << endl;
}