#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define print(n) cout<<n<<endl
int M=100111;
int mod=1000000007;
int main(){string l;cin>>l;ll top=1,below=0;int n=l.size();for(int i=0;i<n;i++){if(l[i]=='1'){below=(3*below+top)%mod;top=2*top%mod;}else	below=3*below%mod;}cout<<(top+below)%mod<<endl;;}