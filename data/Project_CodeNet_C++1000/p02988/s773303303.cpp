#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int P[N];
    for(int i=0;i<N;i++)
    cin>>P[i];
    int Q=0;
    for(int i=1;i<N-1;i++)
    {
        if(P[i-1]<P[i] && P[i]<P[i+1]){
            Q++;
        }
        if(P[i-1]>P[i] && P[i]>P[i+1]) 
        {
           Q++;
        }
    }
    cout<<Q;
}