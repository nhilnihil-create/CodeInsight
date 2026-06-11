#include <bits/stdc++.h>
using namespace std;
int main()
{
    string p;
    cin>>p;
    int l=p.size();
    if(p[l-1]=='s')
    {
        cout<<p<<"es"<<endl;
    }
    else
    {
        cout<<p<<"s"<<endl;
    }
}
