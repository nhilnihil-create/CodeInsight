#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define mp make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<30)
#define LLINF (1LL<<60)
//#define MOD 998244353
#define MOD 1000000007
#define PI 3.14159265358979
using ll = long long;
using namespace std;

int main(){
    int h,w;
    string s[2005];
    cin>>h>>w;
    rep(i,h){
        cin>>s[i];
    }
    int l[2005][2005]={},r[2005][2005]={},u[2005][2005]={},d[2005][2005]={};
    int ans=0;

    rep(i,h){//y
        rep(j,w){//x
            if(j==0){
                if(s[i][j]!='#') l[i][j]=1;
            }
            else{
                if(s[i][j]!='#') l[i][j]=l[i][j-1]+1;
            }
        }
    }
    for(int i=w-1;i>=0;i--){
        rep(j,h){
            if(i==w-1){
                if(s[j][i]!='#') r[j][i]=1;
            }
            else{
                if(s[j][i]!='#') r[j][i]=r[j][i+1]+1;
            }
        }
    }
    rep(i,w){
        rep(j,h){
            if(j==0){
                if(s[j][i]!='#') u[j][i]=1;
            }
            else{
                if(s[j][i]!='#') u[j][i]=u[j-1][i]+1;
            }
        }
    }
    rep(i,w){
        for(int j=h-1;j>=0;j--){
            if(j==h-1){
                if(s[j][i]!='#') d[j][i]=1;
            }
            else{
                if(s[j][i]!='#') d[j][i]=d[j+1][i]+1;
            }
        }
    }

    rep(i,w){
        rep(j,h){
            int count=l[j][i]+r[j][i]+u[j][i]+d[j][i]-3;
            ans=max(ans,count);
        }
    }
    cout<<ans<<endl;
    return 0;
}
