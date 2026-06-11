#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long ttl=0ll;
    for(long long i=1ll;i*i<=n-1ll;i++){
        if((n-1ll)%i==0ll){
            if(i!=1ll&&(n)%i!=0)
                ttl++;
            if(n%((n-1)/i)!=0&&(n-1)/i!=i)
            ttl++;
        }
    }
    for(long long i=1ll;i*i<=n;i++){
        if(n%i==0ll){
            if(i!=1ll){
                long long tmn=n;
                while(tmn%i==0)
                    tmn/=i;
                if((tmn-1)%i==0)
                    ttl++;
            }
            if(i==(n/i))
                continue;
            long long tmn=n;
            while(tmn%(n/i)==0){
                tmn/=(n/i);
            }
            if((tmn-1)%(n/i)==0)
                ttl++;
        }
    }
    cout<<ttl<<'\n';
    return 0;
}
