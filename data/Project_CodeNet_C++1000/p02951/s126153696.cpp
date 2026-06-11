
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int add=(b+c);
    int sub=(add-a);
    if(a<add)
    {
        cout<<sub<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }


}

