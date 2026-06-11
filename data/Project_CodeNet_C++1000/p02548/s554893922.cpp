#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int b = 0;
    
    for(int a=1; a<=n-1; a++){
        b += (n-1)/a;
        
    }
    cout << b << endl;
}