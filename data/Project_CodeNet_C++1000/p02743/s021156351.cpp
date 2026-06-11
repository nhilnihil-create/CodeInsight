#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, c;
    cin >> a >> b >> c;

    if(c <= a + b){
        cout << "No" << endl;
        return 0;
    }

    long long int left = 4 * a * b;
    long long int right = (c-a-b) * (c-a-b);
    if(left < right) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}