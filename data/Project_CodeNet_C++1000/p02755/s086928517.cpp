#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int i=0;
    while(1){
        if (int(i*0.08)==A && int(i*0.1)==B){
            cout << i << endl;
            return 0;
        }
        if (int(i*0.08)>A || int(i*0.1)>B) break;
        i++;
    }
    cout << -1 << endl;
}
 