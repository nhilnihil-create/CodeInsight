#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
#define all(x) x.begin(),x.end()
#define l_b lower_bound
#define u_b upper_bound
#define pb push_back
#define MOD 1000000007
void fastio(void);

ll cnt[sz];

int main(){
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n,sum=0,num,la,lb;
    cin>>n;
    for(la=1;la<=n;la++){
        cin>>num;
        sum+=num;
        cnt[num]++;
    }

    ll q;   cin>>q;
    while(q--){
        ll b, c;
        cin>>b>>c;
        ll dif=c-b;
        sum+=cnt[b]*dif;
        cnt[c]+=cnt[b];
        cnt[b]=0;
        cout<<sum<<endl;
    }

    return 0;
}

void fastio(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}