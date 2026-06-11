#include<bits/stdc++.h>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

int main()
{
    fastIO();

    string x;
    cin>>x;
    int sz=x.size();
    if(x[sz-1]=='s')
        x+="es";
    else
        x+="s";
    cout<<x<<endl;

    return 0;
}

