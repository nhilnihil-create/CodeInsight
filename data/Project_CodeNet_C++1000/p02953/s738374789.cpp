#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000
const int MOD = 1000000007;


int main(){
    /*A
    int a,b,c;
    cin>>a>>b>>c;
    int x = a-b;
    if(c-x>=0)
    {
        cout<<c-x<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    */

    int n;
    cin>>n;
    vector <int> h(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    bool flag = true;
    for(int i=n-1;i>0;i--)
    {
       if(h[i]-h[i-1]>=0)
       {
           continue;
       }
       else if(h[i]-h[i-1]==-1)
       {
           h[i-1]=h[i-1]-1;
       }
       else
       {
           flag = false;
       }
    }
    if(flag)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    return 0;
}