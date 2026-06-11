// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#define pb emplace_back
#define LOCAL
  
using namespace std;
  
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+5;
typedef long long ll;
typedef pair<int,int> Pii;
 
template <typename T>inline void read(T& t){
    char c=getchar();t=0;
    int f=1;
    while(!isdigit(c)){
       if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c))t=t*10+c-48,c=getchar();
    t=f*t;
}
  
template <typename T,typename... Args> inline void read(T& t,Args&... args){
    read(t);read(args...);
}
 
int main(){
    int t=1;
    // read(t);
    while(t--){
        ll n,d;
        read(n,d);
        int ans=0;
        for(int i=1;i<=n;i++){
            ll x,y;
            read(x,y);
            if(x*x+y*y<=d*d){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}