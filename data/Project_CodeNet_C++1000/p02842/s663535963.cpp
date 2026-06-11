#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        long double tmp = (long double)i * 1.08;
        int ttmp = tmp;
        if(ttmp==n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;

    return 0;
}