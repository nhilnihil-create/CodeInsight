#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,g;
    bool tacno=true;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> g;
        if(g%2==0 && g%3!=0 && g%5!=0)
        {tacno=false;break;}
    }
    if(tacno) cout << "APPROVED";
    else cout << "DENIED";
}
