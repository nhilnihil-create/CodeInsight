#include <iostream>
#include <vector>
using namespace std;

int cnt;

void insert(int *a, int n, int g)
{
    for(int i = g;i < n;i++)
    {
        int v = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > v)
        {
            a[j+g] = a[j];
            j -= g;
            cnt++;
        }
        a[j + g] = v;
    }
}

void shell(int *a, int n)
{
    cnt = 0;
    vector<int> g;
    g.push_back(1);
    for(int h = 1*3 + 1;h < n;h = h*3 + 1)
        g.push_back(h);
    cout<<g.size()<<endl;
    for(int i = g.size() - 1; i >= 0;i--)
    {
        cout<<g[i]<<" ";
        insert(a, n, g[i]);
    }
    cout<<endl;
    cout<<cnt<<endl;
}


int main()
{
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i = 0;i < n;i++)
        cin>>a[i];
    shell(a, n);

    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<endl;
    }

    delete [] a;
}
