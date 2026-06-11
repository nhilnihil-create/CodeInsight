#include<bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const long long MOD=(long long)(1e9+7);
const int NAX=1005;
const int MAXN=1000005;
Int N,M,K;
Int W,H;
Int X,Y,Z;
vector<Int> A;
int spf[MAXN];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 


Int perform(Int x){
    return (x*(x+1))/2LL;
}

Int getFactors(int x){
    Int ans=1;
    Int temp=x;
    while(temp!=1){
        int iter=0;
        int prime=spf[temp];
        while(temp%prime==0){
            temp/=prime;
            ++iter;
        }
        ans*=(iter+1);
    }
    return ans;
}
int main()
{
    string S;cin>>S;
    string ans=S;
    if(S.back()=='s') ans+="es";
    else ans+="s";
    cout<<ans<<"\n";
}