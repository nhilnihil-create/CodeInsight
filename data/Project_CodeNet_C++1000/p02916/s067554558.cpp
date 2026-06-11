


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

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,aa,bb,cc,i,j,ar[10000],br[10000],cr[10000];
ii>>n;
FOR(i,1,n+1,1){
ii>>cc;
ar[i]=cc;
}
FOR(i,1,n+1,1){
ii>>cc;
br[i]=cc;
}
FOR(i,1,n,1){
ii>>cc;
cr[i]=cc;
}
int ss=0;
aa=ar[1];
ss=br[aa];
FOR(i,2,n+1,1){
    aa=ar[i-1];
    bb=ar[i];

if((aa+1)==bb){
    //oo<<aa<<" "<<br[aa]<<" "<<cr[aa-1]<<el;

    ss=ss+br[bb]+cr[bb-1];
}
else{
    ss=ss+br[bb];
}


}
oo<<ss;


}