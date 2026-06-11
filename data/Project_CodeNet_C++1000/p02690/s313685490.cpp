#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x;
    cin >> x;
    int a, b;
    int ok = false;
    for(int i = 120; i >= 0 ; i--){
        for(int j = i - 1; j >= -64; j--){
            if(pow(i, 5) - pow(j, 5) == x){
                a = i, b = j;
                ok = true;
                break;
            }
            if(pow(i, 5) - pow(j, 5) > 1000000000)  break;
        }
        if(ok)  break;
    }
    cout << a << " " << b << endl;
    return 0;
}