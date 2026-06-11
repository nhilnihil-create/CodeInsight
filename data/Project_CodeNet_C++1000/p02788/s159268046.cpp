#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;
#define error(args...)                       \
{                                            \
    cerr<<"LINE "<<__LINE__;                 \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
    cerr<<endl;                              \
}
void err(istream_iterator<string> it)
{
} 
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr<<' '<< *it << " = " << a ;
  err(++it, args...);
}

typedef long long ll;
const ll MOD = 1e9 + 7;
const int N = 2e5 + 1, M = 1e3+1, OO = 0x3f3f3f3f;
bool cmp(pair<int,int> a,pair<int,int> b){return a.first<b.first;}
pair<int,int> arr[N];
ll csum[N],ans =0,d,a;
int n;


int main()
{
  scanf("%d%lld%lld",&n,&d,&a);
  d<<=1;
  for(int i=1;i<=n;++i)
  {
    int x,h;
    scanf("%d%d",&x,&h);
    arr[i].first=x,arr[i].second=h;
  }
  sort(arr+1,arr+n+1,cmp); 
  for(int i=1;i<=n;++i)
  {
    int x=arr[i].first,h=arr[i].second;
    csum[i]+=csum[i-1];
    h-=csum[i];
    if(h<=0) continue;

    int idx=upper_bound(arr+1,arr+n+1,make_pair(x+d,-1),cmp)-arr;
    ll req=ceil(h*1.0/a);
    csum[i]+=a*req;
    csum[idx]-=a*req;
    ans+=req;
  }
  printf("%lld\n",ans);
  #ifdef _LOCAL_DEFINE
  cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
  #endif
  return 0;
}