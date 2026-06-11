#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >>k;
    if(k==1){
        cout << 0;
    }
    else{
        cout << n-k;
    }
}