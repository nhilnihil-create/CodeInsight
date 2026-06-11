#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int seg[2000005][26];
string a;
void build(int ver,int tl,int tr)
{
    if(tl>tr)
        return ;
    else if(tl==tr)
    {
        seg[ver][a[tl]-'a']=1;
    }
    else
    {
        int tm=(tl+tr)/2;
        build(2*ver,tl,tm);
        build(2*ver+1,tm+1,tr);
        for(int i=0;i<26;i++)
            seg[ver][i]=seg[2*ver][i]+seg[2*ver+1][i];
    }
}

void upd(int ver,int tl,int tr,int pos,int val,int k)
{
    if(tl>tr)
        return ;
    else if(tl==tr)
    {
        seg[ver][val]+=k;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(tm>=pos)
            upd(2*ver,tl,tm,pos,val,k);
        else
            upd(2*ver+1,tm+1,tr,pos,val,k);
        for(int i=0;i<26;i++)
            seg[ver][i]=seg[2*ver][i]+seg[2*ver+1][i];
        
    }
}

int get(int ver,int tl,int tr,int l,int r,int ind)
{
    if(tl>tr||l>r||tr<l||r<tl)
        return 0;
    else if(tl==l&&tr==r)
        return seg[ver][ind];
    else
    {
        int tm=(tl+tr)/2;
        return get(2*ver,tl,tm,l,min(tm,r),ind)+get(2*ver+1,tm+1,tr,max(tm+1,l),r,ind);
    }    
}

signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n;
    cin>>n;

    cout<<(n+1)/2;    

} 

