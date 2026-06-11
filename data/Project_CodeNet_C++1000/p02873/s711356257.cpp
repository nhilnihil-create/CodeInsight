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
const int MOD=1000000007;
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

//初項1，末項n，項数nの数列の和を求める
long long int series_sum(long long int n){
    return n*(n+1)/2;
}

int main(){
    string s;
    cin>>s;
    int d=0,m=0,p=0,l=0,r=0;
    ll ans=0;
    vector<int> vec;
    rep(i,s.length()){
        if(d==0&&s[i]=='>'){
            m++;
        }else if(d==1&&s[i]=='<'){
            p++;
        }else if(d==0&&s[i]=='<'){
            d=1;
            vec.push_back(-m);
            p=1;
            m=0;
        }else if(d==1&&s[i]=='>'){
            d=0;
            vec.push_back(p);
            p=0;
            m=1;
        }
    }
    if(p!=0)vec.push_back(p);
    if(m!=0)vec.push_back(-m);
    for(int i=0;i<vec.size();i++){
        if(i==0){
            if(vec[i]<0){
                ans+=series_sum(-vec[i]);
            }
            if(vec[i]>0){
                ans+=series_sum(vec[i]-1);
                ans+=max(vec[i],-vec[i+1]);
            }
        }else{
            if(vec[i]<0){
                ans+=series_sum(-vec[i]-1);
            }
            if(vec[i]>0){
                ans+=series_sum(vec[i]-1);
                if(i+1<vec.size())ans+=max(vec[i],-vec[i+1]);
                else ans+=vec[i];
            }
        }
    }
    out(ans);
}
