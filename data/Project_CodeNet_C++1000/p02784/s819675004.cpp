#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool comp1(pair<int,int> &a,pair<int,int> &b)
{
    return a.second>b.second;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int h,n;
    cin>>h>>n;
    int a;
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a;
        s+=a;
    }
    if(s>=h) cout<<"Yes";
    else cout<<"No";
}