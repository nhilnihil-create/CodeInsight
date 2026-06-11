#include <bits/stdc++.h>
using namespace std;
int main(void){
    int d, t, s;
    cin >> d >> t >> s;
    int ans;
    ans = t*s;
    if (ans >= d){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}