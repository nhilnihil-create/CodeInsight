#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=1e6+10;

int n;
int a[N];
int state=2;
bool primes[N];
int q[N];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int main(){
    scanf("%d",&n);
    int now_gcd;
    for(int i=0;i<n;++i){
        int t;
        scanf("%d",&t);
        q[i]=t;
        a[t]++;
    }
    memset(primes,true,sizeof(primes));
    primes[1]=false;
    for(int i=2;i<N;++i){
        if(primes[i]==false) continue;
        int cnt=0;
        cnt+=a[i];
        for(int j=2;i*j<N;++j){
            primes[i*j]=false;
            cnt+=a[i*j];
            if(cnt>1) state=1;
        }
    }
    now_gcd=gcd(q[0],q[1]);
    for(int i=2;i<n;++i){
        now_gcd=gcd(now_gcd,q[i]);
    }
    if(now_gcd!=1) state=0;

    if(state==0) printf("not coprime\n");
    else if(state==1) printf("setwise coprime\n");
    else printf("pairwise coprime\n");
    return 0;
}