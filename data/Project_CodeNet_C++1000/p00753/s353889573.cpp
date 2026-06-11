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

bool IsPrime(int n)
{
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while(cin>>n,n)
    {
        int cnt=0;
        for(int i=n+1;i<=2*n;i++){
            if(IsPrime(i)) cnt++;
        }
        cout<<cnt<<endl;
    }
}