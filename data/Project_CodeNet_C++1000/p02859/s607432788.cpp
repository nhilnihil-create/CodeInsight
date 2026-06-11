#include<bits/stdc++.h>

using namespace std;
const float pi = 3.14159;
int area(int r){
    return r * r;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int r;
    cin >> r;
    cout << area(r) << endl;
}