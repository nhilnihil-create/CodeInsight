

#include<bits/stdc++.h>
#define lli long long int
#define in int
#define el endl
#define oo cout
#define ii cin
#define pb push_back
#define bg begin()
#define en end()
#define p1 first
#define p2 second
#define FOR(i,a,b,c) for (int i = (a); i < (b); i=i+(c))
#define ROF(i,a,b,c) for (int i = (a); i > (b); i=i-(c))
using namespace std;

//vector< pair<lli,lli> >ccr;
//vector< pair<lli,lli> >jjr;
//vector<string>r;
//int ar[100008],br[100008];

int main()
{


int n,aa,bb,cc,i,j;
ii>>n;
vector<lli>v,u;
FOR(i,0,n+1,1){
ii>>cc;
v.pb(cc);
//ar[i]=cc;
}
FOR(i,0,n,1){
ii>>cc;
u.pb(cc);
//br[i]=cc;
}
lli ss=0;

FOR(i,0,n,1){

    if(v[i]>u[i]){
    ss+=u[i];
    u[i]=0;
    }
    else{
        ss+=v[i];
        u[i]-=v[i];
    }

if(u[i]>0){
        if((v[i+1])>u[i]){
        ss+=u[i];
        v[i+1]-=u[i];
        }
        else{
            ss+=v[i+1];
            v[i+1]=0;
}
}
}
oo<<ss<<el;
return 0;
}

