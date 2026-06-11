#include<bits/stdc++.h>
using namespace std;int a[25],p[10],i,j,n,q;
int main(){p[0]=1;for(i=1;i<10;i++){p[i]=p[i-1]*10;}
    while(true){memset(a,0,sizeof(a));
        cin>>a[0]>>q;if(a[0]==0){break;}
        for(i=1;i<25;i++){
            n=0;
            for(j=9;j>=0;j--){
                for(int k=0;k<q;k++){
                    if((a[i-1]/p[k])%10==j){
                        a[i]+=j*p[q-1-n];
                        a[i]-=j*p[n];n++;
                    }
                }
            }
            for(j=0;j<i;j++){
                if(a[i]==a[j]){cout<<j<<' '<<a[i]<<' '<<i-j<<endl;goto E;}
            }
        }
        E:;
    }
}