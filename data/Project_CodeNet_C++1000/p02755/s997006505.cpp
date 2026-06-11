#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    b = 10 * b;
    int ans;
    for (int i = 0; i < 10; i++)
    {        
        if(floor((double)(b+i)*0.08) == a){
            ans = b + i;
            break;
        }
        ans = -1;
    }
    cout << ans << endl;   
    return 0;
}