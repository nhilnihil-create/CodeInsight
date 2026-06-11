#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b,judge = 0,ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if(a == b)judge ++;
        else judge = 0;
        if(judge == 3){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}