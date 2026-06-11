#include <iostream>
#include <string.h>
#define ll long long
using namespace std;


void printA(int *A,int size)
{
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
}
void scanA(int *A,int size)
{
    for(int i=0;i<size;i++)
        cin>>A[i];
}



int sum(int n);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a[4];
    cin>>a;
    if(a[1]=='R')
    {
        cout<<"ABC";
    }
    else
        cout<<"ARC";

}




