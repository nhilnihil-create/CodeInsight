#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b && a!=c || b==c && b!=a || c==a && c!=b)
        cout << "Yes";
    else
        cout << "No";
}
