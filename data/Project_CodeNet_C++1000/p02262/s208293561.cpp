#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

#define MAX_N 1000000

using namespace std;

long long cnt;
int l;
int A[MAX_N];
int n;
vector<int> G;

void InsertionSort(int A[], int n, int g)
{
    for(int i=g; i<n; i++)
    {
        int v=A[i];
        int j=i-g;
        while(j>=0 && A[j]>v)
        {
            A[j+g]=A[j];
            j-=g;
            cnt++;
        }
        A[j+g]=v;
    }
}

void ShellSort(int A[], int n)
{
    for(int h=1; ;)
    {
        if(h>n)
            break;
        G.push_back(h);
        h=3*h+1;
    }
    reverse(G.begin(), G.end());
    for(int i=0; i<G.size(); i++)
        InsertionSort(A, n, G[i]);
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        scanf("%d", A+i);
    cnt=0;
    ShellSort(A,n);
    cout<<G.size()<<endl;
    for(int i=0; i<G.size(); i++)
    {
        if(i>0)
            printf(" ");
        printf("%d",G[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    for(int i=0; i<n; i++)
        printf("%d\n", A[i]);
    return 0;
}

