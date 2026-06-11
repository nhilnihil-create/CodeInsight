#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a,b;
    cin >> a >> b;
    if(b<a){
    for (int i = 0; i < a; i++) {
    cout << b;
    }
    }
    else{
    for (int i = 0; i < b; i++) {
    cout << a;
    } 
    }
}