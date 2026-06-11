#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    int y = x;
    while(true){
        bool ok = true;
        for(int i=2; i<y; i++){
            if(y % i == 0){
                ok = false;
                break;
            }
        }
        if(ok) break;
        y++;
    }
    cout << y << endl;
}
