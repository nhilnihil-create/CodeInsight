#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,a,b,ans,ans2;
    cin>>n>>a>>b;
    ans=min(n-a,b-1);
    if((b-a)%2==0){
        ans=min(ans,(b-a)/2);
    }
    else if((b-a)%2==1){
        long long ans2=min(a+(b-a-1)/2,n-b+1+(b-a-1)/2);
        ans=min(ans,ans2);
    }
    cout<<ans<<endl;
    return 0;
}
