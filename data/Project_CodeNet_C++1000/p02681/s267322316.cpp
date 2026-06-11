#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int c=0;
    for(int i=0; i<b.size()-1; i++)
    {
        if(a[i]!=b[i])
            c++;
    }
    if(c==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
