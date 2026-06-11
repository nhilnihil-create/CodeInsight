#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,i;
    cin>>a>>b>>c>>d;
    for(i=0; ;i++)
    {
        if(a<=0||c<=0)
            break;
        if(i%2)
            a-=d;
        else
            c-=b;
    }
    cout<<(a<=0?"No":"Yes")<<endl;
}
