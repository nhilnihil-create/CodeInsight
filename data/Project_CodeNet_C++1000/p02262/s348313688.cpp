#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
#define maxn 1000005
int a[maxn];
int n;//size of the array
vector<int> G;
int cnt=0;
void insertionSort(int g)
{
   for(int i=g;i<n;i++)
   {
       int key=a[i];
       int j=i-g;
       while(j>=0&&a[j]>key)
       {
           a[j+g]=a[j];
           j=j-g;
           cnt++;
       }
       a[j+g]=key;
   }
}
void makeShellArray()
{
    int num=1;
    for(num;;)
    {
        if(num>n)
            break;
        G.push_back(num);
        num=3*num+1;
    }
}
void shellSort()
{
    int m=G.size();
    for(int i=m-1;i>=0;i--)
    insertionSort(G[i]);
}
void print()
{
    int m=G.size();
    cout<<m<<endl;
    for(int i=m-1;i>=0;i--)
    {
       if(i!=0)
        cout<<G[i]<<" ";
       else
        cout<<G[i]<<endl;
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        makeShellArray();
        shellSort();
        print();
    }
    return 0;
}