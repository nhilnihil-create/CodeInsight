#include <bits/stdc++.h>
#include<string>
#define mod 1000000007
using ll = long long;
using namespace std; 

int main(){
    string n; cin >> n;
    for (auto a : n){
        if (a=='7') {
            cout << "Yes" << "\n";
            return 0;
        }
    }
    cout << "No" << "\n";
}

