#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;
    
    int A = max(a,b);
    int B = min(a,b);
    for(int i = 0 ; i < A ; i++){
        cout << B;
    }
    cout << endl;
}