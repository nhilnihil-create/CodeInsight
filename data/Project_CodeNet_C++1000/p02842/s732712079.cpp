#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t,kk,pk;
     cin>>t;
     kk=t/1.08;
     pk=(kk+1)*1.08;
     if(kk*1.08==t)
        cout<<kk<<endl;
     else if(pk==t)
        cout<<kk+1<<endl;
     else
        cout<<":("<<endl;
}

