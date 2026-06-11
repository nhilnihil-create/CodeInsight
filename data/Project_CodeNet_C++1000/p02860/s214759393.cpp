/**
 * author  : UshanGhosh
 * created : 2020-09-19 17:35:23
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
    string s;
    cin>>n>>s;
    if(n%2) cout<<"No\n";
    else{
        ll err = 0;
        for(i=0;i<n/2;i++){
            if(s[i]!=s[i+n/2]) err++;
        }
        if(!err) cout<<"Yes\n";
        else cout<<"No\n";
    }
}