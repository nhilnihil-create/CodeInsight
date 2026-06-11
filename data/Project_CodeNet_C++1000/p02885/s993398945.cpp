#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;    
    if(2*b >= a){
        cout << 0;
        return 0;
    }
    cout << a - 2*b;
    return 0;
}
