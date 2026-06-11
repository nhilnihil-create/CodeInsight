#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, n, i;
    cin >> n;
    for(i=1;i<=9;i++) {
        if(!(n%i) && (n/i)<=9) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}