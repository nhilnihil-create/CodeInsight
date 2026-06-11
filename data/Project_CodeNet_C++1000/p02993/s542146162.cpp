#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    string n;
    cin >> n;

    for (int i = 0; i < n.length()-1; i++) {
        if (n[i] == n[i+1]) {
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;
}