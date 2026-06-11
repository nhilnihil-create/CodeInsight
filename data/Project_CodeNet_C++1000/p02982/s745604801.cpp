#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,d,ans=0,dd,ddd;
    cin>>n>>d;
    long long x[n][d];
    f(i,0,n){
        f(j,0,d){
            cin>>x[i][j];
        }
    }
    f(i,0,n){
        f(j,i+1,n){
            dd=0;
            f(k,0,d){
                dd+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
            }
            ddd=sqrt(dd);
            if(ddd*ddd==dd){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
