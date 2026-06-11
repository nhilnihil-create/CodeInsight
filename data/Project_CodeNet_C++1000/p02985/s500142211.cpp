#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "No" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

int BE(int b,int e){
    int r=1;
    while(e){
        if(e&1){
            r=(r*b)%MOD;
        }
        b=(b*b)%MOD;
        e >>=1;
    }
    return r;
}

vector<int> fact_norm,fact_inv;
void fact_inverse(int N){
    REP(i,N+1){
        fact_norm.push_back(1);
        fact_inv.push_back(1);
    }
    for(int i=1;i<=N;i++){
        fact_norm[i]=(fact_norm[i-1]*i)%MOD;
    }
    for(int i=0;i<=N;i++){
        fact_inv[i]=BE(fact_norm[i],MOD-2);
    }
}

int Perm(int n,int r){
    if(n<r)return 0;
    int R=1;
    R*=fact_norm[n];R%=MOD;
    R*=fact_inv[n-r];R%=MOD;
    return R;
}


signed main(void){
    int N,K;
    int a[114514],b[114514];
    cin >> N >> K;
    REP(i,N-1){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    int child[114514]={};
    int parent[114514]={};
    
    vector<int> G[114514];
    REP(i,N-1){
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    bool visited[114514]={};
    queue<int> Q;
    Q.push(0);
    parent[0]=-1;
    
    while(!Q.empty()){
        int q=Q.front();
        Q.pop();
        if(visited[q])continue;
        visited[q]=true;
        
        REP(i,G[q].size()){
            if(!visited[G[q][i]]){
                Q.push(G[q][i]);
                parent[G[q][i]]=q;
                child[q]++;
            }
        }
    }
    
    REP(i,N){
        visited[i]=false;
    }
    Q.push(0);
    
    int Ans=K;
    fact_inverse(114514);
    /*REP(i,N){cout << fact_norm[i] << " ";}cout << endl;
    REP(i,N){cout << (fact_norm[i]*fact_inv[i])%MOD << " ";}cout << endl;*/
    
    while(!Q.empty()){
        int q=Q.front();
        Q.pop();
        if(visited[q])continue;
        visited[q]=true;
        
        if(parent[q]==-1){
            Ans*=Perm(K-1,child[q]);
            Ans%=MOD;
        }else{
            Ans*=Perm(K-2,child[q]);
            Ans%=MOD;
        }
        //cout << q MM Ans << endl;
        
        REP(i,G[q].size()){
            if(!visited[G[q][i]]){
                Q.push(G[q][i]);
            }
        }
    }
    cout << Ans << endl;
    return 0;
}

