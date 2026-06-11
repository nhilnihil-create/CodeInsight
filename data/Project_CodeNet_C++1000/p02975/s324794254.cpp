#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mkpr(x1,x2) make_pair(x1,x2)
typedef long long int ll;


//stack<char> stk;
set<ll> sll;
//set<pair<ll,ll>> spll;
//map<string,ll> mp;
//map<pair<ll,ll>,ll>::iterator iter;
map<ll,ll> mp;
//deque<ll> deq;
vector<ll> vll;
//ll num[ten52];
//priority_queue<ll> pq;          //decreasing

int main(void)
{
    ll m,n,i,j,k=0,d,pre=0,now;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        if(sll.find(m)==sll.end())
        {
            sll.insert(m);
            vll.pb(m);
        }
        mp[m]++;
        if(mp.size()>3)
        {
            cout<<"No";
            return 0;
        }
    }
    sort(all(vll));
    if(sll.size()==1)
    {
        if(vll[0]!=0) cout<<"No";
        else cout<<"Yes";
    }
    else if(sll.size()==2 && n%3==0)
    {
        if(sll.find(0)==sll.end())
            cout<<"No";
        else
        {
            if(mp[vll[1]]==2*mp[vll[0]]) cout<<"Yes";
            else cout<<"No";
        }
    }
    else if(sll.size()==3 && n%3==0)
    {
        if(((vll[0]^vll[1])^vll[2])!=0)
        {
            cout<<"No";
            return 0;
        }
        if(mp[vll[0]]==mp[vll[1]]&&mp[vll[0]]==mp[vll[2]])
            cout<<"Yes";
        else
            cout<<"No";
    }
    else cout<<"No";
    return 0;
}
