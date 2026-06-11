#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k, n;
    string s;
    cin>>k>>s;
    n  = s.size();
    if(n>k)
    {
        for(int i=0;i<k;i++)
        {
            cout<<s[i];
        }
        cout<<"...";
    }
    else
    {
        cout<<s;
    }
    cout<<endl;
    return 0;
}
