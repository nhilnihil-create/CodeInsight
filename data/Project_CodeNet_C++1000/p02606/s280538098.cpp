#include<iostream>
using namespace std;
int main()
{
    int L,R,n;
    cin>>L>>R>>n;
    int x=R-L+1;
    int L1=L;
    int cont=0;
    for(int i=0;i<x;i++)
    {
        if((L1+i)%n==0)
        {
            cont++;
        }
    }
   cout<<cont;
}
