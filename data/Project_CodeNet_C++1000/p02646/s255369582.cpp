#include <iostream>
#include <sstream>
using namespace std;
#include <bits/stdc++.h>
#include<utility>
#include <algorithm>
#include<iterator>
#define  go return 0
#define rep(i,n) for(int i=0;i<n;++i)
#define rep(j,m) for(int j=0;j<m;++j)
#define REP(i,n) for(int i=1;i<=n;++i)
#define all(v)   ((v).begin()), ((v).end())
#define len(s)   ((int)s.size())
#define F first
#define S second
#define pb push_back
#define pf push_front
#define mp make_pair
typedef long long ll;
typedef double db;
typedef vector<int> ve;
typedef vector<pair<ll,ll> >vepa;
typedef set<string>se;
typedef map<int ,int> mpp;
const int N=1e5+5 ,OO=1e18;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
ll TC,n,mx,arr[N];
bool vis[N],f;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
      ll a ,v,b,w,t;
      cin>>a>>v>>b>>w>>t;
      if(a>b)
        swap(a,b);
      if(b-a<=(v-w)*t)
        cout<<"YES";
      else
        cout<<"NO";
go;
}
