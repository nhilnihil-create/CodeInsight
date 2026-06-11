#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
typedef long long ll;
typedef pair<int,int> P;

template<typename A,typename B> inline void chmin(A &a,B b){if(a>b) a=b;}
template<typename A,typename B> inline void chmax(A &a,B b){if(a<b) a=b;}
//-----------------------------------------------------------------------

const int N=123456*2;
bool isPrime[N+1];

void calc()
{
// N=123456*2?????§????´???°????±???????
    for(int i=2;i<=N;i++) isPrime[i]=true;
    for(int i=2;i<=N;i++){
        if(!isPrime[i]) continue;
        for(int j=2*i;j<=N;j+=i){
            isPrime[j]=false;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    calc();

    int n;
    while(cin>>n,n)
    {
        int cnt=0;
        for(int i=n+1;i<=2*n;i++){
            if(isPrime[i]) cnt++;
        }
        cout<<cnt<<endl;
    }
}