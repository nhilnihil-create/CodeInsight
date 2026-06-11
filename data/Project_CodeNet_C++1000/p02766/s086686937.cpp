#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,br=0,p=1;
    cin >> n >> k;
    while(p<=n)
    {
        br++;
        p*=k;
    }
    cout << br;
}
