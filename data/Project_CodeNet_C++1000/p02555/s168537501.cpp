/**
 * author  : UshanGhosh
 * created : 2020-09-20 15:01:00
**/ 

#include<bits/stdc++.h>
using namespace std;

#define    ll      long long
#define    pii     pair<int,int>
#define    vii     vector<int>
#define    vcc     vector<char>
#define    pll     pair<long long, long long>
#define    mem     memset
#define    sof     sizeof
#define    co1     __builtin_popcountll
#define    PB      push_back
#define    UB      upper_bound
#define    LB      lower_bound
#define    MP      make_pair
#define    TS      to_string
#define    F       first
#define    S       second
#define    pi      acos(-1)
#define    mod     (int)1e9+7
#define    inf     (long long)1e18
#define    endl    '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,d,e,f,i,j,k,m,n,o,x,y;
    ll tar;
    cin>>tar;
    if(tar<3){
      cout<<0<<'\n';
      return 0;
    }
    vii v;
    for(i=3;i<=tar;i++) v.PB(i);
    n = v.size();
    ll ar[tar+1];
    memset(ar,0,sizeof(ar));
    ar[0] = 1;
    for(i=3;i<=tar;i++){
        for(j=0;j<n;j++){
            if(i-v[j]>=0){
                ar[i] += ar[i-v[j]];
                ar[i]%=mod;
            }
        }
    }
    cout<<ar[tar]<<"\n";
}