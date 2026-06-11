#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    int thr;
    for (int x=1; x<n+1; x++){
        thr = (x*108.0)/100.0;
        if (thr == n){
            cout << x << endl;
            return 0;
        } 
    }
    cout << ":(" << endl;
    return 0;
}
