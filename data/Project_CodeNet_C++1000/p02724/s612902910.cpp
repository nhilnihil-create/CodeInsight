#include<bits/stdc++.h>
#include<string>

using namespace std;

int X;

void solve (){
    cout << ((X / 500) * 1000) + ((X % 500) / 5 * 5);
}


int main() {
    cin >> X;
    solve();
}
