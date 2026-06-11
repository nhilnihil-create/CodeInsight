#include<iostream>
//#include <cmath>
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define ROF(i,a,n) for(int i=(a);i>(n);--i)

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 //   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n;ld d;cin>>n>>d;
    int cnt=0;
    while(n--){
        ld x,y; cin>>x>>y;
        if(pow(x*x+y*y,0.5)<=d) cnt++;
    }
    cout<<cnt;
    return 0;
}