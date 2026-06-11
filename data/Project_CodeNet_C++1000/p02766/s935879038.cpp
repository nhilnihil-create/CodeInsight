#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; ; i++){
        n /= k;
        if(n == 0){
            cout << i << endl;
            break;
        }
    }
}