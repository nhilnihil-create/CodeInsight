#include <bits/stdc++.h>
using namespace std;
void insertionSort(int a[],int num,int b,int &cnt){
    int key,j;
    for(int i=b;i<num;i++)
    {
        key=a[i];
        j=i-b;
        while(j>=0&&a[j]>key)
        {
            a[j+b]=a[j];
            cnt=cnt+1;
            j=j-b;
        }
        a[j+b]=key;
    }}
void shellsort(int a[],int num)
{
    int m,cnt=0;
    for (int i=0;pow(3,i)*1.5-0.5<num;i++)
        m=i+1;
    cout<<m<<endl;
    int g[m];
    for (int i=0;i<m;i++)
        g[i]=pow(3,i)*1.5-0.5;
    for(int i=m-1;i>=0;i--)
        insertionSort(a,num,g[i],cnt);
    for(int i=m-1;i>=0;i--)
        if(i==0) cout<<g[i]<<endl;
        else cout<<g[i]<<" ";
    cout<<cnt<<endl;
    for(int i=0;i<num;i++) cout<<a[i]<<endl;
}
int main()
{
    int num;
    cin>>num;
    int a[num];
    for(int i=0;i<num;i++) {
        cin>>a[i];
    }
    shellsort(a,num);
    return 0;
}

