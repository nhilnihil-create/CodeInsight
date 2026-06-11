#include <bits/stdc++.h>

using namespace std;

int n, r;

int main(){
    cin >> n >> r;
    cin.ignore();

    if(n >= 10){
        cout << r << endl;
        return 0;
    }

    cout << r + 100 * (10 - n) << endl;
    return 0;
}
