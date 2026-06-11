#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 10000005
#define pb push_back
#define mp make_pair
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;

bool prime[MAX];
int lowFactor[MAX];
void SIEVE(void){  /// 10^6 lowest factors stored ; O(Nlog(log(N)))
    for(int i=1;i<MAX;i++){
        prime[i]=true;
        lowFactor[i]=i;
    }
    prime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(!prime[i]) continue;
        for(int j=i*i;j<MAX;j+=i){
            prime[j]=false;
            if(lowFactor[j]==j) lowFactor[j]=i;
        }
    }
}

lint getFactorization(int a){ /// O(log(n)); n<10^6/10^7
    lint ans=1;
    while(a>1){
        int pre=lowFactor[a];
        int cong=0;
        while(lowFactor[a]==pre){
            pre=lowFactor[a];
            a/=pre;
            cong++;
        }
        if(cong) ans*=(cong+1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    SIEVE();
    int n;
    cin>>n;
    lint sm=0;
    for(int i=1;i<=n;i++){
        sm+=i*getFactorization(i);
    }
    cout<<sm;
    return 0;
}

