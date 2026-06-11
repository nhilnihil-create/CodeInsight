#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int MAXN=100100;
int a[10],b[10],c[10];
int main()
{
    ios;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) a[i]=i;
    int cnt=1,ans1,ans2;
    int flag1=0,flag2=0;
    do{
        int f1=1, f2=1;
        if(!flag1){
            for(int i=1;i<=n;i++){
                if(a[i]!=b[i]){
                    f1=0; break;
                }
            }
            if(f1){
                ans1=cnt;
                flag1=1;
            }
        }
        if(!flag2){
            for(int i=1;i<=n;i++){
                if(a[i]!=c[i]){
                    f2=0; break;
                }
            }
            if(f2){
                ans2=cnt;
                flag2=1;
            }
        }
        if(flag1 && flag2) break;
        cnt++;
    }while(next_permutation(a+1,a+1+n));
    cout<<abs(ans1-ans2)<<'\n';
    return 0;
}