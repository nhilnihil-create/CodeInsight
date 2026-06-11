#include <bits/stdc++.h>
using namespace std;

#define gap " "
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ok cout<<"ok"<<endl
#define dbg(x) cout<<(#x)<<" is "<<x<<endl
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N=1000009;
const int sq=1100; //sieve size
int vis[sq+5],prime[sq],flag,ar[N];
map<int,int> mpp;
void sieve()
{
   int k=0; 
   for(int i=4; i<=sq; i+=2) vis[i]=1;
   prime[k++]=2;

   for(int i=3; i<=sq; i+=2){
        if(vis[i]==0){
            prime[k++]=i;
            for(int j=i+i; j<=sq; j+=i){
                vis[j]=1;
            }
        }
   }
}

void factor(int n)
{
    int idx=0,pf=prime[idx++];

    while(pf*pf<=n){
        if(n%pf==0)
        {
            while(n%pf==0) n/=pf;
            if(mpp.find(pf)!=mpp.end()){
            flag=1;
            return;
           }
            mpp[pf]=1;
        }
        pf=prime[idx++];
    }
    if(n!=1) {
        if(mpp.find(n)!=mpp.end()) {
            flag=1;
            return;
        }
        mpp[n]=1;
    }
}
int main()
{
    sieve();
    int n,i;
    flag=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&ar[i]);

        if(!flag) factor(ar[i]);
       
    }
    if(!flag){
        printf("pairwise coprime\n");
        return 0;
    }
   
    int gc=ar[1];
    for(i=2; i<=n; i++){
        gc=__gcd(gc,ar[i]);
    }
    gc==1? printf("setwise coprime\n"):printf("not coprime\n");
    return 0;
}