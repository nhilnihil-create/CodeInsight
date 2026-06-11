#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,br=0;
    long long d,d1,g,x,y;
    cin >> n >> d;
    d1=d*d;
    for (int i=0;i<n;i++)
    {
        cin >> x >> y;
        if(x*x+y*y<=d1)
            br++;
    }
    cout << br;
}
