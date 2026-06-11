#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)

ll N;
ll ans[505][505];
ll i, j,k, ans2;
int main(){
    scanf("%lld", &N);

    fornum(i,0,N){
        fornum(j,i+1,N){
            fornum(k,1,30){
                ll a = (1 << k) - 1;
                if((i&a)!=(j&a)){
                    if(k>ans2){
                        ans2 = k;
                    }
                    printf("%lld ", k);
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}