#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y;
    cin >> X >> Y;
    int ans = 0;
    for (int i = 0; i < X + 1; i++){
        if(4 * i + 2 * (X - i) == Y)
            ans = 1;
    }
    if(ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}