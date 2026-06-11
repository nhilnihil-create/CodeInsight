#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x;
    cin >> x;
    cout << (x/100*5 >= x%100 ? 1 : 0) << endl;
    return 0;
}