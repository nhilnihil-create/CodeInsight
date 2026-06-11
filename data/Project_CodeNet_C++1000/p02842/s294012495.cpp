#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, tmp;
    cin >> n;
    tmp = n / 1.08;
    if ((int)(tmp * 1.08) == n){
        cout << tmp << endl;
    } else if ((int)((tmp+1) * 1.08) == n){
        cout << tmp+1 << endl;
    } else{
        cout << ":(" << endl;
    }
    return 0;
}