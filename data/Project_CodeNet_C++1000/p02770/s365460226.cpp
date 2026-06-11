#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
using namespace std;
typedef pair<int,int> P;//Pでpair<-,->を表す。
typedef long long LL; 
LL MOD=1000000007;

int main()
{ 
    int k,q;
    cin>>k>>q;
    LL D[k];
    LL d[k];
    LL s[k+1];
    s[0]=0;
    for(int i=0;i<k;i++){
        cin>>D[i];
    }

    LL N[q];
    LL X[q];
    LL M[q];
    LL ans[q];
    for(int i=0;i<q;i++){
        cin>>N[i]>>X[i]>>M[i];
    }

    for(int Q=0;Q<q;Q++){
        LL n,x,m;
        n=N[Q];x=X[Q];m=M[Q];
        for(int i=0;i<k;i++){
            d[i]=D[i]%m;
            if(d[i]==0){d[i]=m;}
        }
        for(int i=1;i<=k;i++){
            s[i]=s[i-1]+d[i-1];
        }
        LL a=(n-1)/k;
        LL b=(n-1)%k;
        LL c=a*s[k]+s[b]+(x%m);
        ans[Q]=n-(c/m)-1;
    }
    for(int i=0;i<q;i++){cout<<ans[i]<<endl;}
    return 0;
}