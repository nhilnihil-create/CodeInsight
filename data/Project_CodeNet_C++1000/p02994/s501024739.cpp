#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N,L;cin>>N>>L;
    int a;
    int sum=0;
    int absmini=300;
    int minimu;
    rep(i,N){
        a=L+i;
        sum+=a;
        if(absmini>abs(a)){
            absmini=abs(a);
            minimu=a;
        }
    }
    sum-=minimu;
    cout<<sum<<endl;
}

