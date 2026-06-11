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
        int k;
        read(k);
        int sum=7,ans=-1;
        for(int i=0;i<1e7;i++){
            if(sum%k==0){
                ans=i+1;
                break;
            }
            sum=(sum*10+7)%k;
        }
        printf("%d\n",ans);
    }
    return 0;
}