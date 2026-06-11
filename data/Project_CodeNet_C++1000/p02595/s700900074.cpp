#include<bits/stdc++.h>
using namespace std;
int main()
{
    double N,D,X,Y,d,count=0;
    cin>>N>>D;
    for(int i=0;i<N;i++)
    {
        cin>>X>>Y;
        d=sqrt((X*X)+(Y*Y));
        if(d<=D){
           count++;
        }

    }
    cout<<count<<endl;
    return 0;
}