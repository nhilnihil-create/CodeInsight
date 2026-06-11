#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

/*2進数配列+1*/
vector<int> twoadd(vector<int> v, int N){
    v[N-1]+=1;
    int ind = N-1;
    int j=N-1;
    for(j=N-1;j>=1;j--){
        if(v[j]>1){
            v[j-1]+=1;
            v[j]=0;
        }
    }
    return v;
}

/*フィボナッチ*/
long long fibonatti(long long d){
    long long count = 0;
    long long f1 = 1;
    long long f2 = 1;/*ここを変える*/
    long long temp;
    if(d == 1){
        count = f1;
    }else if(d == 2){
        count = f2;
    }else if(d==0){
        count = 1;
    }else{
        for(int i=0;i<d-2;i++){
            temp = f1+f2;
            f1 = f2;
            f2 = temp;
        }
        count = temp;
    }
    return count;
}

/*最大公約数*/
unsigned long long GCD(long long L,long long R){
    if(L>R){
        long long temp=R;
        R = L;
        L = temp;
    }
    unsigned long long pp=0,ppt=0;
    unsigned long long ans=0;
    if(R%L==0){
        ans = L;
    }else{
        while(true){
            ppt = pp;
            pp=R%L;
            if(pp == 0){
                ans = ppt;
                break;
            }
            R = L;
            L = pp;
        }
    }    
    return ans;    
}

/*最小公倍数*/
unsigned long long LCM(long long L,long long R){
    unsigned long long ans;
    unsigned long long gcd = GCD(L,R);
    ans = (L/gcd)*R;
    return ans;
}

/*Combination set*/
#define mod 1000000007
#define maxcomb 3000/*大きいものを求めるときはここを変える*/
vector<long long> fc(maxcomb+1);
vector<long long> ifc(maxcomb+1);
long long modpow(long long x,long long n){
    long long ans = 1;
    while(n > 0){
        if(n & 1) {
            ans = ans*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return ans;
}
void Conb(){
    fc[0]= 1;
    ifc[0]=1;
    for(long long i=0;i<maxcomb;i++){
        fc[i+1] = fc[i]*(i+1)%mod;//n!(mod)
        ifc[i+1] = ifc[i]*modpow(i+1,mod-2)%mod;//k!^{M-2} (mod)
    }
}
unsigned long long Combination(long long L,long long R){
    unsigned long long up=1,ans;
    Conb();
    if(L==0&&R==0){
        return 1;
    }else if(L<R||L<0){
        return 0;
    }else{
        long long t = ifc[L-R]*ifc[R]%mod;
        ans = t*fc[L]%mod;
    }
    return ans;
}
/*Combination set ここまで*/

/*素数判定*/
bool isPrime(int x){
    int i;
    if(x < 2){
        return 0;
    }else if(x == 2){
        return 1;
    }
    if(x%2 == 0) {
        return 0;
    }
    for(i = 3; i*i <= x; i += 2){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}

/*桁和*/
int digsum(int n) {
    int res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

/*約数の数*/
long long countdivisor(long long K){
    long long N = sqrt(K);
    bool b = false;
    if(sqrt(K)-N==0){
        b= true;
    }
    long long count =0;
    for(int i=0;i<N;i++){
        if(K%(i+1)==0){
            count++;
        }
    }
    if(b==false){
        count *= 2;
    }else{
        count = (count-1)*2+1;
    }
    return count;
}

/*約数列挙*/
vector<long> Alldivisor(long n){
    vector<long> ret;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

/*特定の文字カウント*/
int stringcount(string s,char c){
    return count(s.cbegin(),s.cend(),c);
}

/*Graph*/
using Graph = vector<vector<int>>; //グラフ型
struct Edge{
    int to; //辺の行き先
    int weight; //辺の重み
    Edge(int t,int w):to(t),weight(w){}
};
using WGraph = vector<vector<Edge>>;
/*vector<int> first_order; //行きがけ順
vector<int> last_order; //帰りがけ順 */
/*重みなし有向*/
Graph WeightlessGraph(int N,int M){
    Graph G(N);
    vector<bool> m(N,false);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
    }
    return G;
}
/*重みなし無向*/
Graph WeightlessNoDirectionGraph(int N,int M){
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    return G;
}
/*重みつき*/
WGraph WeightGraph(int N,int M){
    WGraph G(N);
    for(int i=0;i<M;i++){
        int from, to ,weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to,weight));
    }
    return G;
}
/*深さ優先探索*/
vector<bool> seen;
//vector<ll> ans;
void dfs(const Graph &G, int s,int p){
    seen[s]=true;
    /*if(p!=-1){
        ans[s]+=ans[p];
    }*/
    for(auto next_v:G[s]){
        if(seen[next_v]){
            continue;
        }
        dfs(G,next_v,s);
    }
}


/*ここから*/
int main() {
    int N,K;
    cin >> N >> K;
    int ans=0;
    vector<bool> S(N);
    for(int i=0;i<N;i++){
        char c;
        cin >> c;
        if(c=='L'){
            S[i] = 0;
        }else{
            S[i] = 1;
        }
    }
    int count=0;
    int count1=0;
    for(int i=0;i<N-1;i++){
        if(S[i]==1&&S[i+1]==1){
            ans++;
        }
        if(S[i]==1&&S[i+1]==0){
            count++;
        }
        if(S[i]==0&&S[i+1]==1){
            count1++;
        }
    }
    for(int i=1;i<N;i++){
        if(S[i]==0&&S[i-1]==0){
            ans++;
        }
    }
    for(int i=0;i<N-1;i++){
        if(S[i]==1&&S[i+1]==0){
            ans+=2;
            K--;
        }
        if(K>=1&&i==N-2&&S[N-1]==1&&S[0]==0){
            ans++;
        }
        if(K==0){
            break;
        }
    }
    if(count==1&&count1==0){
        ans--;
    }
    cout << ans << endl;
    return 0;
}
/*REの時vectorのoverflow確認*/