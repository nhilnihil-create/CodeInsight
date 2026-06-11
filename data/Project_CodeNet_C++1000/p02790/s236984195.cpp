#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,g=0;
    cin >> a >> b;
    if(a>b)
        swap(a,b);
    for (int i=0;i<b;i++)
        g=g*10+a;
    cout << g;
}
