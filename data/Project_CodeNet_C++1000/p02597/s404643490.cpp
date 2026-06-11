#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
int main(void)
{
    int n;
    ll ans = 0;
    cin>>n;
    vector<bool> stone(n+4);
    ll lastred =0;
    vector<ll> red;
    rep(i,n)
    {
        char c;
        cin>>c;
        if(c=='R')
        {
            stone[i]=false;
            lastred = i;
            red.push_back(i);
        }
        else stone[i]=true;

    }

    sort(red.begin(),red.end(),greater<ll>());
    auto itr = red.begin();
    for(int i=0;i<n;i++)
    {
        if(stone[i]==true)
        {
           if(itr!=red.end())
           {
               if(*itr>i)
               {
                    swap(stone[i],stone[*itr]);
                    itr ++;
                    ans ++;
               }
           }


            
            
        }
    }
    cout<<ans<<endl;
}