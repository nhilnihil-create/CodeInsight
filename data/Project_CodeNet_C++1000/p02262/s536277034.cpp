#include<bits/stdc++.h>
using namespace std;
vector <int> ve;
const int maxn = 1000010;
long long cnt = 0;
int num[maxn];

void InsertionSort(int n,int g)
{
    for(int i=g;i<n;i++)
    {
        int v = num[i];
        int j = i-g;
        while(j>=0 && num[j] > v)
        {
            num[j+g] = num[j];
            j -= g;
            cnt++;
        }
        num[j+g] = v;
    }
}

void ShellSort(int n)
{
    int h = 1;
    while(h <= n)
    {
        ve.push_back(h);
        h = h*3 + 1;
    }

    for(int i=ve.size()-1;i>=0;i--)
        InsertionSort(n,ve[i]);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    ShellSort(n);
    printf("%d\n",ve.size());
    for(int i=ve.size()-1;i>=0;i--)
    {
        printf("%d",ve[i]);
        if(i != 0)
            printf(" ");
    }
    printf("\n");
    printf("%lld\n",cnt);
    for(int i=0;i<n;i++)
    {
        printf("%d",num[i]);
        if(i != n-1)
            printf("\n");
    }
    return 0;
}