#include <bits/stdc++.h>
using namespace std;
int main(){
        long long int x; cin >> x;
        long long int b = 100, step = 0;
        while (b < x){
            b += b * 1 / 100;
            step++;
        }
        cout << step << endl;
    return 0;
}

