#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int a = 1; a <= 9; ++a)
    {
        for(int b=1; b<=9; ++b)
        {
            if(a*b == n){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}