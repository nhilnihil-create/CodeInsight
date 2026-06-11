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
//set<pair<ll,ll>> spll;
map<string,ll> mp;
map<string,ll>::iterator mpit;
//map<ll,ll> mp;
//deque<ll> deq;
vector<ll> vll;
ll num[ten52];
//priority_queue<pair<ll,ll>> pq;          //decreasing


int main(void)
{
    ll m=0,n,i=0,j,k=0;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        sort(all(s));
        mp[s]++;
    }
    for(auto &au: mp)
    {
        j=au.second;
        m+=(j)*(j-1)/2;
    }
    cout<<m;
    return 0;
}
