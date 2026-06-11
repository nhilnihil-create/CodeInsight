#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,X;
    int List[N+1];
    List[0]=0;
    int s;
    int count=0;
    cin>>N>>X;
    
    for(int i=0;i<N;i++)
    {
    cin>>s;
    List[i+1]=List[i]+s;
    }
    for(int i=0;i<=N;i++)
    {
        if(List[i]<=X){
        count++;
        }
        else{
        break;
        }
    }
    cout<<count;
 return 0;
}