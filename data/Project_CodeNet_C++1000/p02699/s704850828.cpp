#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int sum[9000000]={};
long long mm=1e9+7;
/*long long poww(long long a,long long b){
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    long long v=poww(a,b/2);
    v*=v;
    v%=mm;
    if(b%2==1){
        v*=v;
        v%=mm;
    }
    return v;
}*/    //function to pow
/*long long pow2(long long k){
long long j=2;
while(--k)
    {j*=2;
    j%=mm;}
return j;


}*/
/*bool prime[100000];
vector<long long >v;
void sieve(){
prime[0]=prime[1]=true;
long int n=10000;
int t=sqrt(n);
for(long int i=2;i<=n;++i){
    if(prime[i]==false){
        v.push_back(i);
        for(long int p=i*i;p<=n;p+=i)
            prime[p]=true;
    }
}
}*/
int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     long long n,w;
     cin>>n>>w;
     if(w>=n)
        cout<<"unsafe";
     else
        cout<<"safe";

    return 0;
}
