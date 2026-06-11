#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int mn = b * 10;
    while (true){
        int c = mn * 0.08;
        int d = mn * 0.1;
        if((c == a) && (b == d)){
            cout << mn << endl;
            return 0;
        }
        mn++;
        if(mn > 11000){
            cout << -1 << endl;
            return 0;
        }
    }
}