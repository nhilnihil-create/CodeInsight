#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin>>N;
    vector<int>X(N);
    for (int i = 0; i < N; i++)
    {
        cin>>X[i];
    }
    
    priority_queue<int,vector<int>,greater<int>>Sum;

    for (int P = 1; P < 101; ++P)
    {
        int cash=0;
        for(int i=0;i<N;++i)
        {
            int x=X[i];
            cash += (x-P)*(x-P);
        }
        Sum.push(cash);
    }

    cout<<Sum.top()<<endl;


    return 0;
}