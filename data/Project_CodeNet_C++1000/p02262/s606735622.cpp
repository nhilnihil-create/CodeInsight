#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
int power(int a,int x)
{
    if(x==0)
        return 1;
    else if (x==1)
        return a;
    else
        return power(a,x-1)*a;
}
void insertSort(vector<int> &a,int g)
{
    unsigned int i;
    int v,j;
    for(i=g;i<a.size();i++)
    {
        v = a[i];
        j = i-g;
        while(j>=0&&a[j]>v)
        {
            a[j+g]=a[j];
            j -= g;
            cnt++;
        }
        a[j+g]=v;
    }
}
void shellSort(vector<int> &a,const vector<int> &g)
{
    for(unsigned int i=0;i<g.size();i++)
        insertSort(a,g[i]);
    return ;
}
int main()
{
    int n,m;
    unsigned int i,length;
    vector<int> input,g;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        input.push_back(m);
    }
    for(i=31;i>=0;i--)
    {
        if((n>>i)%2==1)
            break;
    }
    length = i+1;
    m=power(2,i);
    for(i=0;i<length;i++)
    {
        g.push_back(m);
        m /= 2;
    }
    shellSort(input,g);
    cout<<g.size()<<endl;
    for(i=0;i<g.size();i++)
    {
        if(i)
            cout<<' ';
        cout<<g[i];
    }
    cout<<endl<<cnt<<endl;
    for(i=0;i<input.size();i++)
        cout<<input[i]<<endl;
    return 0;
}