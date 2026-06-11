#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <cctype>
//小文字を大文字 c-0x20;


#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define vvll(z,a,b) vector<vector<ll>>z(a,vector<ll>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) c.begin(),c.end()
#define fix(k) fixed<<setprecision(k)
#define PI 3.141592653589793
#define sizestr(i,x)  size_t i=x.length();
using namespace std;



int main(){
int n,k;cin>>n>>k;
vi a(n);
rep(j,n)cin>>a.at(j);
int flag=0;
rep(i,k){
    vi sum(n+2);
    rep(j,n){
        int b=j+1-a.at(j);
        if(b<=0)b=1;
        int c=j+1+a.at(j);
        if(c>n)c=n;
        sum.at(b)+=1;
        sum.at(c+1)-=1;
    }
    for(int h=1;h<=n;h++){
       if(h==1){
            a.at(h-1)=sum.at(h);
           continue;
       }
        sum.at(h)+=sum.at(h-1);
        a.at(h-1)=sum.at(h);
    }

/*rep(hu,n){
    a.at(hu)=sum.at(hu+1);
}*/
rep(h,n){
    if(a.at(h)==n){
        if(h==n-1){
            flag++;
            break;
        }
        continue;
    }
    break;
}
if(flag)break;
}



rep(g,n){
cout<<a.at(g)<<" ";
}
cout<<endl;
}
