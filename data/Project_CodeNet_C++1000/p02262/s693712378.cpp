#include<bits/stdc++.h>
using namespace std;

int n;
long long cnt;
int a[1000001];
int l;
vector<int> g;

void insertion(int a[], int n, int g)
{
    for(int i=g;i<n;i++)
    {
        int v = a[i];
        int j = i - g;
        while(j>=0 && a[j]>v)
        {
            a[j+g] = a[j];
            j -= g;
            cnt++;
        }
        a[j+g] = v;
    }
}

void shell(int a[], int n)
{
    for(int i=1; ; )
    {
        if(i>n) break;
        g.push_back(i);
        i = i*3 + 1;
    }
    for(int i=g.size()-1;i>=0;i--)
    {
        insertion(a, n, g[i]);
    }
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cnt = 0;

    shell(a, n);

    cout<<g.size()<<endl;
    for(int i=g.size()-1;i>=0;i--)
    {
        cout<<g[i];
        if(i) cout<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}

