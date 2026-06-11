#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=1000000000000000000,mod=1000000007,BS,k;
#define en printf("\n");

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ll a,b,c,k;
        cin>>a>>b>>c>>k;
        ll sum=0;
        while(b<=a)
        {
            b*=2;sum++;
        }
        while(c<=b){
            c*=2;sum++;
        }
        if(k>=sum)
        cout<<"Yes";
        else
        cout<<"No";
}
