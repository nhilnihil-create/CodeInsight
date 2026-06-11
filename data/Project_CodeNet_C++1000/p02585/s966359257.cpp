#include<bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    UnionFind tree(N);

    vector<int> p(N), c(N);

    for(int i = 0; i < N; i++) {
        cin>>p[i];
        p[i]--;
    }
    for(int i=0;i<N;++i){
        tree.unite(p[p[i]],p[i]);
    }
    for(int i = 0; i < N; i++) {
        cin>>c[i];
    }
    if(K==1){
        sort(c.begin(),c.end());
        cout<<c[N-1]<<endl;
        return 0;
    }
    set<int>a;
    for(int i=0;i<N;++i){
        a.insert(tree.root(p[i]));
    }
    long long ans=-1e18;
    for(auto x:a){
        int s=x;
        vector<int>b;
        for(int j=0;j<N;++j){
            b.push_back(s);
            s=p[s];
            if(s==b[0])break;
        }
        int size=b.size();
        long long sum[size+1];
        sum[0]=0;
        for(int j=0;j<size;++j){
            sum[j+1]=sum[j]+c[b[j]];
        }
        if(K%size==0){
            ans=max(ans,sum[size]*(K/size));
        }
        else if(K/size>0){
            ans=max(ans,sum[size]*(K/size-1));
        }
        for(int j=0;j<size;++j){
            long long preto=-1e18;
            for(int k=1;k<=size;++k){
                if(j+k<=size){
                    preto=max(preto,sum[j+k]-sum[j]);
                }
                else{
                    preto=max(preto,(sum[size]-sum[j])+sum[k-(size-j)]);
                }
                if(K/size>0){
                    if(sum[size]>0){
                        if(K%size<k){
                            ans=max(ans,preto+sum[size]*(K/size-1));
                        }
                        else ans=max(ans,preto+sum[size]*(K/size));
                    }
                    else ans=max(ans,preto);
                }
                else{
                    if(k<=K){
                        ans=max(ans,preto);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
