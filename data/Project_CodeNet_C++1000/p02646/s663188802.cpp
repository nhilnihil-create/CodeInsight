#include <bits/stdc++.h>
using namespace std;
int main(void){
    long a[2], b[2], t;
    
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> t;
    
    if(a[1] <= b[1]){
        cout << "NO";
    }
    else{
        if((a[1] - b[1]) * t >= abs(a[0] - b[0])){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
    
    return 0;
}
