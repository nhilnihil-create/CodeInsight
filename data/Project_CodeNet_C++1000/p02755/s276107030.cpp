#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    for(int i = 0; i <= 1010; i++) {
        if(a==floor(i*0.08) && b==floor(i*0.1)){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}