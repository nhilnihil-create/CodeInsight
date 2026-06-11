#include<iostream>
#include<vector>

using namespace std;

int cnt=0;
vector<int> g;
vector<int> a;

void insertion_sort(int n,int g)
{
    for(int i=g;i<n;i++)
    {
        int v=a[i];
        int j=i-g;

        while(j>=0&&a[j]>v)
        {
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }



}

void shell_sort(int n)
{
    cnt=0;
    for(int i=1;i<=n;i=i*3+1)
    {
        g.push_back(i);
    }
    int m=g.size();
    for(int i=m-1;i>=0;i--)
    {
     insertion_sort(n,g[i]);
    }
}

int main()
{

    int n;

    cin>>n;

    int b;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        a.push_back(b);
    }

    shell_sort(n);

    cout<<g.size()<<endl;

    for(int i=g.size()-1;i>=0;i--)
    {
        if(i!=g.size()-1)
        {
            cout<<" ";
        }

        cout<<g[i];
    }

    cout<<endl<<cnt<<endl;

    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}

