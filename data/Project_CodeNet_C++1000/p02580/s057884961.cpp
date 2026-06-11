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
#define ten53 300005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mkpr(x1,x2) make_pair(x1,x2)
typedef long long int ll;


//stack<char> stk;
//set<ll> sll;
set<pair<ll,ll> > spll;
//map<string,ll> mp;
//map<pair<ll,ll>,ll>::iterator iter;
//map<ll,ll> mp;
//deque<ll> deq;
vector<pair<ll,ll> > vh(ten53),vw(ten53);
//vector<ll> vll;
ll numh[ten53],numw[ten53];
//priority_queue<pair<ll,ll>> pq;          //decreasing

int main(void)
{
    ll m,n,i,j,k=0,d,pre=0,now,h,w,inh,inw,bh=0,bw=0;
    string s;
    cin>>h>>w>>m;
    if(m==1)
    {
        cout<<1;
        return 0;
    }
    for(i=1;i<=m;i++)
    {
        cin>>inh>>inw;
        spll.insert(mkpr(inh,inw));
        vh[inh].first--;
        vh[inh].second=inh;
        vw[inw].first--;
        vw[inw].second=inw;
    }
    sort(all(vh));
    sort(all(vw));
    bh=-vh[0].first;
    bw=-vw[0].first;
    for(i=0;i<m;i++)
    {
        if(bh>-vh[i].first) break;
        bh=-vh[i].first;
        for(j=0;j<m;j++)
        {
            if(bw>-vw[j].first) break;
            bw=-vw[j].first;
            pre=bw+bh;
            if(spll.find(mkpr(vh[i].second,vw[j].second))!=spll.end())
            {
                pre--;
                k=max(k,pre);
            }
            else
            {
                cout<<pre;
                return 0;
            }
        }
    }
    cout<<k;
    return 0;
}
