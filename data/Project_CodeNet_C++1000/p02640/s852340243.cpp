#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,y;
    cin >> x >> y;
    if(y%2==0 && 2*x<=y && y<=4*x)
        cout << "Yes";
    else
        cout << "No";
}
