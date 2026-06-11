#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    string b;
    cin>>b;
    for(int i=0; i<b.size(); i++)
    {
        if((b[i]+a)>90)
        {
            printf("%c",'A'+(a-('Z'-b[i])-1));
        }
        else
            printf("%c",b[i]+a);
    }
    cout<<endl;
}
