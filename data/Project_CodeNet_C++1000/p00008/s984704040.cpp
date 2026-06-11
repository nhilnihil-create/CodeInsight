#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    for(int m=0;m<10;m++){
                        if(j+k+l+m==n){
                            ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}