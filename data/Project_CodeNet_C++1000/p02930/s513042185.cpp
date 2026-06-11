#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int k;
            for(k=0;(i>>k&1)==(j>>k&1);k++);
            printf("%d%c",k+1," \n"[j==n]);
        }
    }
}
