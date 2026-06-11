#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    long long broj=1e18,g,p=1;
    bool tacno=true;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> g;
        if(g==0)
        {p=0;tacno=true;break;}
        if(tacno)
        {
            if(g>broj/p) tacno=false;
            else p*=g;
        }
    }
    if(tacno)
        cout << p;
    else
        cout << -1;
}
