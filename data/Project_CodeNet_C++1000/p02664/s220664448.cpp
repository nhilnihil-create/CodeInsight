#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define INF (ll)1e18

char S[202020];
ll Sn;
ll i, j, k;
vector<ll> anss;

int main(){
    scanf("%s", S);
    Sn = strlen(S);
    fornum(i,0,Sn){
        if(S[i]=='?'){
            printf("D");
        }else{
            printf("%c", S[i]);
        }
    }
    return 0;
}