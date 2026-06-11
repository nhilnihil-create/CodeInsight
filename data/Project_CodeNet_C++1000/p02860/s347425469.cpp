#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,d;
    string S,T,Temp;
    cin>>N;
    d=N/2;
    cin>>S;

    for(int i=0;i<d;i++)
    {
       T += S[i];

    }
    Temp=T+T;
    if(!S.compare(Temp)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }



    return 0;
}