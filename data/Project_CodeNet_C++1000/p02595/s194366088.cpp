#include <bits/stdc++.h>
using namespace std;

int main()
{

int N,d;
int count=0;
cin>>N>>d;
int x,y;
for(int i=0;i<N;i++)
{
    cin>>x>>y;
    if(sqrt(pow(x,2)+pow(y,2))<=d)
    {
        count++;
    }
}

cout<<count<<endl;




    return 0;
}
