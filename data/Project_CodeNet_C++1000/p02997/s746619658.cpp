#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long

int main(){
    int n,k; cin >> n >> k;
    if((n-1)*(n-2)/2 -k<0){
        printf("%d\n",-1);
        return 0;
    }
    printf("%d\n",n-1+(n-1)*(n-2)/2 -k);
    rep(i,n-1){
        printf("%d %d\n",1,i+2);
    }
    int res=1;
    for(int i=2;i<n;++i){
        for(int j=i+1;j<=n;++j){
            if(res>(n-1)*(n-2)/2 -k) break;
            printf("%d %d\n",i,j);
            res++;
        }
    }
    return 0;
}