 
#include <bits/stdc++.h>
 
 
#define ll long long int  
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(n) for (int i = 0; i < n; ++i) 
#define REP(i,k,n) for (int i = k; i <= n; ++i) 
#define REPR(i,k,n) for (int i = k; i >= n; --i)
 
 
using namespace std;

int cnt[1000005],a[1000005];
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main() {
    int n,f1=1;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int t=a[i];
        for(int j=2;j*j<=t;j++)
        {
            if(t%j==0)
            {
                while(t%j==0) t/=j;
                cnt[j]++;
                if(cnt[i]>1)
                {
                    f1=0;
                    break;
                }
            }
        }
        if(t>1){
            cnt[t]++;
            if(cnt[t]>1)
            {
                f1=0;
                break;
            }
        }
        if(f1==0) break;
    }
    if(f1){
        cout<<"pairwise coprime"<<endl;
        return 0;
    }
    int now=a[1];
    for(int i=2;i<=n;i++) 
        now=gcd(now,a[i]);
    if(now==1) 
        cout<<"setwise coprime"<<endl;
    else 
        cout<<"not coprime"<<endl;
    return 0;
}