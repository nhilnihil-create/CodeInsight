#include<stdio.h>
#include<algorithm>
#include<vector>
#include <iostream>
using namespace std;

long long cnt;
vector<int> G;
int A[1000000];

void insertionSort(int A[],int n,int x)
{
    int t;
    for(int i=0; i<x; i++)
    {

        for(int j=i+x; j<n; j=j+x)
        {
            int k=j;
            while(k-x>=0&&A[k]<A[k-x])
            {
                t=A[k];
                A[k]=A[k-x];
                A[k-x]=t;
                k=k-x;
                cnt++;
            }
        }

    }
}
void shellSort(int A[],int n)
{

    for(int h=1; h<=n; h=3*h+1)
    {
        G.push_back(h);
    }
    for(int i=G.size()-1; i>=0; i--)
    {
        insertionSort(A,n,G[i]);
    }
}

void print(int A[],int n)
{
    for(int i=0; i<n; i++)
        cout<<A[i]<<endl;
}



int main()
{
    cnt=0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>A[i];
    shellSort(A,n);

    cout<<G.size()<<endl;
    for(int i=G.size()-1; i>0; i--)
        cout<<G[i]<<" ";
    cout<<G[0]<<endl;
    cout<<cnt<<endl;
    print(A,n);
    return 0;

}

