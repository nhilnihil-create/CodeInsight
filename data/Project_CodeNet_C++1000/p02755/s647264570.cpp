#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;
    for(int i=1;i<=4000000;i++)
    {
        int X=i*(0.08);
        int Y=i*(0.1);
        if(X==A&&Y==B) { cout<<i<<endl; return 0;}
    }
    cout<<-1<<endl;
}
