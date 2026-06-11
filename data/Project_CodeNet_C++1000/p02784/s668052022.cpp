#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,h,g,br=0;
    cin >> h >> n;
    for (int i=0;i<n;i++)
    {
        cin >> g;
        br+=g;
    }
    if(br>=h)
        cout << "Yes";
    else
        cout << "No";
}
