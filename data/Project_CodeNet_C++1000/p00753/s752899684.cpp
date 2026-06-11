#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<iomanip>
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define loop(i,a,b) for(long long i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<string> vs;
Def inf = sizeof(Def) == sizeof(ll) ? (int)2e18 : (int)1e9+10;
signed main(){
    int n;
    int sos[400000]={0,0,1};
    loop(i,3,400000){
        int t=1;
        for(int j=2;j*j<=i;j++)if(i%j==0)t=0;
        sos[i]=t;
    }
    while(cin>>n,n){
        int co=0;
        loop(i,n+1,n+n+1)co+=sos[i];
        cout<<co<<endl;
    }

}

