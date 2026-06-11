#include <bits/stdc++.h>
using namespace std;;

int main(){
    int n;
    cin >> n;
    n %= 1000;
    cout << (1000-n)%1000 << endl;
}