#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    bool flag = 0;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if(i * j < n){
                count ++;
            }else break;
        }
    }
    cout << count << endl;
}