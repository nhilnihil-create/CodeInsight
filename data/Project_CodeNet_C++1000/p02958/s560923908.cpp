#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    int dif = 0; 
    cin >> n;
    vector<int> p(n);
    for (int i=0;i<n;i++){
        cin >> p.at(i);
        if (p.at(i) != (i+1)){
            dif ++;
        }
    }
    if (dif <= 2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}