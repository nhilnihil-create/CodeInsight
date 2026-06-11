#include<iostream>
using namespace std;
int r[11],l[11],t[11];
int kyes;

void dfs(int i,int j,int k)//j->left,k->right
{
    if(i>10)
    {
        kyes=1;
    }
    if(kyes)
    return;
    if(t[i]>l[j-1])
    {
        l[j]=t[i];
        dfs(i+1,j+1,k);
    }
    if(t[i]>r[k-1])
    {
        r[k]=t[i];
        dfs(i+1,j,k+1);
    }
}
int main()
{
    int i;
    int n;
    cin>>n;
    while(n--)
    {
        for(i=1; i<=10; i++)
            cin>>t[i];
        kyes=0;
        dfs(1,1,1);
        if(kyes)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}