#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>p(n),q(n),k(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    for(int i=0;i<n;i++) k[i]=i+1;
    sort(k.begin(),k.end());
    int a,b;
    int m=0;
    do
    {
        m++;
        if(k==p)
        a=m;
        if(k==q)
        b=m;
    }while (next_permutation(k.begin(),k.end()));
    cout<<abs(a-b)<<"\n";
    
}