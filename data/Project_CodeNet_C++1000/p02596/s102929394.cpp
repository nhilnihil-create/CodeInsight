#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MAX 100000000000000000

void solve(int n)
{
    int tot = 0;
    for(int i=1;i<=(1e7);i++)
    {
        tot = (tot * 10 + 7) % n;
        if(tot==0)
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    return;
}

int main()
{

    //freopen("inputfile.txt","r",stdin);
    IOS;
   int n;cin>>n;
  solve(n);
    return 0;
}
