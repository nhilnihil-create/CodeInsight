#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int tree[1000005];
int lazy[1000005];
void propogate(int i,int l,int r)
{
    tree[i]+=(r-l+1)*lazy[i];
    if(l!=r)
        lazy[i*2]+=lazy[i],lazy[i*2+1]+=lazy[i];
    lazy[i]=0;
}
void update(int i,int l,int r,int l1,int r1,int val)
{
    if(lazy[i])
        propogate(i,l,r);
    if(l1>r1 || l>r1 || l1>r)
        return;
    if(l1<=l && r<=r1)
    {
        tree[i]+=(r-l+1)*val;
        if(l!=r)
            lazy[i*2]+=val,lazy[i*2+1]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,l1,r1,val);
    update(i*2+1,mid+1,r,l1,r1,val);
    tree[i]=tree[i*2]+tree[i*2+1];
}
int query(int i,int l,int r,int l1,int r1)
{
    if(l1>r1 || l>r1 || l1>r)
        return 0;
    if(lazy[i])
        propogate(i,l,r);
    if(l1<=l && r<=r1)
        return tree[i];
    int mid=(l+r)/2;
    return query(i*2,l,mid,l1,r1)+query(i*2+1,mid+1,r,l1,r1);
}

int32_t main() 
{
    IOS
    int n,d,a;
    cin>>n>>d>>a;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int ctr=0;
    for(int i=0;i<n;i++)
    {
        int reduce=query(1,1,n,i,i);
        v[i].second-=reduce;
        if(v[i].second<=0)
            continue;
        int need=v[i].second/a + ((v[i].second % a)!=0);
        ctr+=need;
        int low=i;
        int high=n-1;
        while(low<high)
        {
            int mid=(low+high+1)/2;
            if(v[mid].first-v[i].first>2*d)
                high=mid-1;
            else
                low=mid;
        }
        update(1,1,n,i,low,need*a);
    }
    print(ctr);
}   
