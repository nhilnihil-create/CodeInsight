#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t,arr[100005],kk;
     cin>>t;
     for(int i=0;i<t;i++)
        cin>>arr[i];
     sort(arr,arr+t);
     kk=t/2;
     cout<<arr[kk]-arr[kk-1]<<endl;
}


