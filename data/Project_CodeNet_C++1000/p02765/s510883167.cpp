#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,r;
    cin >> n >> r;
    if(n>=10)
        cout << r;
    else
        cout << r+100*(10-n);
}
