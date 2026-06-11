#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int N;
    cin >> N;
    if(N%10 == 3){
        cout << "bon" << endl;
        return 0;
    }
    int a[] = {2,4,5,7,9};
    rep(i,5){
        if(N%10 == a[i]){
            cout << "hon" << endl;
            return 0;
        }
    }
    cout << "pon" << endl;
}