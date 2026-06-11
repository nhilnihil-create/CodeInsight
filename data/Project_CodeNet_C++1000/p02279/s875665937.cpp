#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}

int depth(vector<int>& parent ,int x){
    if(parent[x]==-1)return 0;
    else return 1+depth(parent,parent[x]);
}

int main(){
    int n;
    in(n);
    vector<int> parent(n,-1);
    vector<vector<int>> children(n);
    int x,y,k;
    rep(i,n){
        in(x,k);
        rep(j,k){
            in(y);
            children[x].push_back(y);
            parent[y]=x;
        }
    }
    rep(i,n){
        printf("node %d: parent = %d, depth = %d, ",i,parent[i],depth(parent,i));
        if(parent[i]==-1)printf("root, ");
        else if(children[i].size()>=1)printf("internal node, ");
        else printf("leaf, ");
        printf("[");
        rep(j,children[i].size()){
            if(j==0)printf("%d",children[i][j]);
            else printf(", %d",children[i][j]);
        }
        printf("]\n");
    }
}
