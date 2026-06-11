#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)

ll N,N2;
char S[202020];
ll mk[202020];
ll mk2[202020];
ll i, j,k, ans;
int main(){
    scanf("%lld%s", &N,S);
    if(S[0]=='W'){
        printf("0");
        return 0;
    }
    N2 = N * 2;
    j = 0;
    k = 1;
    ans = 1;
    fornum(i,1,N2){
        //printf("%lld:%lld\n", i, k);
        j = ((S[i - 1] == S[i]) + j) % 2;
        if(j){
            if(k==0){
                printf("0");
                return 0;
            }
            ans = ans * k % MOD;
            k--;
        }else{
            k++;
        }
        
    }
    if(k==0){
        fornum(i,0,N){
            ans = ans * (i + 1) % MOD;
        }
        printf("%lld", ans);
    }else{
        printf("0");
    }

    return 0;
}