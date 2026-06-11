#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
bool o;
char ch,SSS[1<<17],*A=SSS,*B=SSS;
inline char gc(){
	return A==B&&(B=(A=SSS)+fread(SSS,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,q;
ll a[5001],s[5001],sum;
int g[5001];
int len,seed,mod,tp;
int main(){
	rd(n),rd(q);
	for(int i=1;i<=n;i++) rd(a[i]);
	while(q--){
		rd(len),rd(seed),rd(mod);
		len--;
		seed%=mod;
		for(int i=1;i<=n;i++){
			s[i]=a[i]%mod;
			if(!s[i]) s[i]=mod;
			s[i]+=s[i-1];
		}
		sum=seed+s[n]*(len/n)+s[len%n];
		wr(len-sum/mod),_e;
	}
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (ch^45&&(ch<48||ch>57)) ch=gc();
      	if(ch==45)o=1,ch=gc();
        while(ch>47&&ch<58){
			x=(x<<1)+(x<<3)+(ch^48);
			ch=gc();
		}
      	if(o) x=-x;
 	}
template <typename _Tp>
    inline void wr(_Tp x){
        if(x<0) x=-x,putchar(45);
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }
template <typename _Tp>
	inline _Tp mx(_Tp x,_Tp y){
		return x>y?x:y;
	}
template <typename _Tp>
	inline _Tp mn(_Tp x,_Tp y){
		return x<y?x:y;
	}
