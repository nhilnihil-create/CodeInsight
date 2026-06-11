#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N;
vector<ll> Av;
ll B;

ll i, j, k, ans;


int main(){
    scanf("%lld", &N);
    fornum(i,0,N){
        ll a;
        scanf("%lld", &a);
        Av.push_back(a);
        B ^= a;
    }
    
    fornum(i,0,N){
        Av[i] &= ~B;
    }

    j = 0;
    for (i = 59; i >= 0;i--)
    {
        
        fornum(k,j,N){
            if(Av[k]&(1ll<<i))
                break;
        }
        if(k==N)
            continue;
        if(j<k){
            Av[j] ^= Av[k];
        }
        fornum(k, j+1, N){
            ll a = Av[j] ^ Av[k];
            Av[k] = min(Av[k], a);
        }
        j++;
    }
    fornum(i,0,N){
        ll a = ans ^ Av[i];
        ans = max(a, ans);
    }
    printf("%lld", ans*2 + B);

    return 0;
}