/**
 * author  : UshanGhosh
 * created : 2020-08-27 14:45:30
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
#define    mod     1e9+7
#define    inf     1e18
#define    endl    '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        long long a,b,c,d,e,f,i,j,k,m,n,o,x,y;
        cin>>a>>b>>c;
        a = abs(a);
        ll ans;
        if((a/c)>b){
            ans = a-c*b;
        } 
        else{
            b-=(a/c);
            if(b%2==0) ans = a%c;
            else ans = c-a%c;
        }
        cout<<ans<<"\n";
    }
}