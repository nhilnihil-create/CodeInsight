#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define ll long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll x,y,z,a=0,b=0,c=0,d=0,sum,ans,total,cnt,n,m,k,p,kase,i;
string s1,s2;
#define N 100001
#define MX 1000000001
vector <ll> v;
map<ll,ll> mp;
set<ll> s;
map<ll,ll> :: iterator itr1, ptr1;
set<ll> :: iterator itr, ptr;


int main()
{

    cin>>s1;

    c=0;
    if(s1[2]==s1[3])c++;
    if(s1[4]==s1[5])c++;

    if(c==2)cout<<"Yes";
    else cout<<"No";




    return 0;
}
// Happy Coding  (:
