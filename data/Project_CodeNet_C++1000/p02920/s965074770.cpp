#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////


ll N,Np, S[303030];
priority_queue<ll> aaq;
stack<ll> as,bs;
vector<ll> av;
ll i, j, k,ans;

int main(){
    scanf("%lld",&N);
    Np = 1 << N;
    fornum(i,0,Np){
        scanf("%lld", &S[i]);
    }
    sort(S, S + Np);
    //printf("s");
    fornum(i,0,Np){
        as.push(S[i]);
    }
    av.push_back(as.top());
    as.pop();

    fornum(i,0,N){
        //printf("%d\n", as.size());
        sort(av.begin(), av.end(),greater<ll>());
        fornum(j,0,(1<<i)){
            if(as.empty()){
                break;
            }
            ll a = as.top();
            as.pop();
            if(av[j]>a){
                av.push_back(a);
            }else{
                bs.push(a);
                j--;
            }
        }
        if(j<(1<<i)){
            break;
        }
        while(bs.size()){
            as.push(bs.top());
            bs.pop();
        }
    }
    printf("%s", i == N ? "Yes" : "No");

    return 0;
}