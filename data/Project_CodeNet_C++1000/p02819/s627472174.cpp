#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("avx,avx2,fma,sse,sse2")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
int N = 1e5+7;
typedef tree<int, null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> new_data;
vector<bool>a(N,true);
void prime()
{
    a[0]=false;
    a[1]=false;
    for(int i=4;i<=N;i+=2)a[i]=false;
    for(int i=3;i*i<=N;i+=2)
    {
        if(a[i])
        {
            for(int j=(i*i);j<=N;j+=(2*i))a[j]=false;
        }
    }
}
int main()
{
    prime();
    int x;
    cin>>x;
    for(int i=x;;i++)
    {
        if(a[i]==true)cout<<i<<endl,exit(0);
    }
}
