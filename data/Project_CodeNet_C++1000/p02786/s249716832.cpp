#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int H;
    cin >> H;
    long long int a=log2(H);
    a=pow(2,a+1)-1;
    cout << a << endl;
}