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
     ll m,n,kk;
     cin>>m>>n;
     kk=m*n;
     if(m==1|| n==1)
        cout<<"1"<<endl;
     else if(kk%2==0)
        cout<<kk/2<<endl;
     else
        cout<<kk/2+1<<endl;

}


