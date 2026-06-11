#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, r, rate;
    cin >> n >> r;
    if(n >= 10){
        rate = r;
    } else {
        rate = r + 100*(10-n);
    }
    cout << rate;
    return 0;
}
