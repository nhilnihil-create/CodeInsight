#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,P; string S;
void input()
{
    cin>>N>>P>>S;
}

void solve()
{
    vi count(P,0); 
    ll ans=0;
    if(P==2 || P==5){
        for(ll i=0;i<N;++i){
            if((S[i]-'0')%P==0) ans+=i+1ll;
        }
    }
    else{
        count[0]++;
        reverse(S.begin(), S.end());
        int k=1;
        int sum=0;
        for(int i=0;i<N;++i){
            // sum=(sum*10+S[i]-'0')%P;
            // ans+=count[sum];
            // count[sum]++;
            sum+=((S[i]-'0')*k)%P; sum%=P;
            count[sum]++;
            k*=10; k%=P;
        }
        
        for(int i=0;i<P;++i) {
            ans+=(ll)count[i]*(count[i]-1)/2;
            // cout<<"i:"<<i<<" "<<count[i]<<"\n";
        }
    }
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}