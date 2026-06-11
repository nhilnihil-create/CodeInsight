#include<iostream>
#include<deque>

using namespace std;

int A[200005],B[200005];
int n;

bool ok(int poz)
{
    if(B[poz]==A[poz])
        return 0;

    if(B[poz]-B[(poz-1+n)%n]-B[(poz+1)%n]>0)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>A[i];

    deque<int> Q;
    for(int i=0; i<n; i++)
        cin>>B[i];

    for(int i=0; i<n; i++)
    {
        if(ok(i))
            Q.push_back(i);
    }

    long long rez=0LL;
    while(!Q.empty())
    {
        int vf=Q.front();
        Q.pop_front();

        int nr=(B[vf]-A[vf])/(B[(vf-1+n)%n]+B[(vf+1)%n]);
        B[vf]-=nr*(B[(vf-1+n)%n]+B[(vf+1)%n]);
        rez+=1LL*nr;

        if(nr==0)
        {
            cout<<"-1\n";
            return 0;
        }

        if(ok((vf-1+n)%n))
            Q.push_back((vf-1+n)%n);
        if(ok((vf+1)%n))
            Q.push_back((vf+1)%n);
    }

    for(int i=0; i<n; i++)
    {
        if(A[i]!=B[i])
        {
            cout<<"-1\n";
            return 0;
        }
    }

    cout<<rez<<"\n";
    return 0;
}
