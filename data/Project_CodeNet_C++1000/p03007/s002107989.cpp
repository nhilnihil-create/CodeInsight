#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,a[100001],t;
vector<pair<int,int> > kq;
priority_queue<int> duong;
priority_queue<int,vector<int>,greater<int> > am;

void nhap()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
}

void process()
{
    int vt=1;
    if (a[1]>=0)
    {
        vt++;
        kq.push_back({a[1],a[n]});
        am.push(a[1]-a[n]);
        for (int i=2;i<n;++i)
            duong.push(a[i]);
        t=a[n]-a[1];
    }
    else if (a[n]<0)
        {
            vt++;
            kq.push_back({a[n],a[1]});
            duong.push(a[n]-a[1]);
            for (int i=2;i<n;++i)
                am.push(a[i]);
            t=a[n]-a[1];
        }
        else
        {
            for (int i=1;i<=n;++i)
            {
                if (a[i]<0) am.push(a[i]);
                else duong.push(a[i]);
            }
        }
    for (;vt<n;++vt)
    {
        if (am.size()>=duong.size())
        {
            kq.push_back({duong.top(),am.top()});
            int k=duong.top()-am.top();
            duong.pop();
            am.pop();
            t=k;
            if (k<0) am.push(k);
            else duong.push(k);
        }
        else
        {
            kq.push_back({am.top(),duong.top()});
            int k=am.top()-duong.top();
            duong.pop();
            am.pop();
            t=k;
            if (k<0) am.push(k);
            else duong.push(k);
        }
    }
    cout<<t<<"\n";
    for (auto i:kq)
        cout<<i.first<<" "<<i.second<<"\n";
}

int main()
{
    nhap();
    process();
    return 0;
}
