#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

ll N, B[1010101];
char A[1010101];
ll mk[10];
ll i, j, k;


bool calc(){
    ll i, j, k,ret;
    ret = 0;
    k = 0;
    fornum(i,0,N){
        if(k==0){
            ret ^= B[i] & 1;
        }
        ll a = N - 1 - i;
        if(a==0)
            break;
        while(a%2==0){
            ++k;
            a /= 2;
        }
        a = i + 1;
        while(a%2==0){
            --k;
            a /= 2;
        }
    }
    return ret;
}

int main(){
    scanf("%lld%s", &N,A);
    bool flg = false;
    fornum(i,0,N){
        if(A[i]=='1')
            B[i] = 0;
        if(A[i]=='2'){
            B[i] = 1;
            flg = true;
        }
        if(A[i]=='3')
            B[i] = 2;
    }
    if(calc()){
        printf("1\n");
        return 0;
    }
    fornum(i,0,N){
        B[i] /= 2;
    }
    if(flg||!calc()){
        printf("0\n");
        return 0;
    }
    printf("2\n");
    return 0;
}