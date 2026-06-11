#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
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
template<class T>T updivide(T a,T b){if(b==1) return a;else if(a%b==0) return a/b;else return (a/b)+1;}

int main(){
    INT(n);
    vector<int> vec(n),plus,minus,zero;
    rep(i,n){
        in(vec[i]);
        if(vec[i]>0){
            plus.push_back(vec[i]);
        }
        if(vec[i]<0){
            minus.push_back(vec[i]);
        }
        if(vec[i]==0){
            zero.push_back(0);
        }
    }
    int d=0;
    while(d!=zero.size()){
        d++;
        if(plus.size()<minus.size()){
            plus.push_back(0);
        }
        else if(plus.size()>=minus.size()){
            minus.push_back(0);
        }
    }
    vector<pair<int,int>> ope;
    int m=0;
    if(plus.size()>=1&&minus.size()>=1){
        sort(all(plus));
        sort(rall(minus));
        for(int i=1;i<plus.size();i++){
            ope.push_back(make_pair(minus[0],plus[i]));
            minus[0]-=plus[i];
        }
        for(int i=0;i<minus.size();i++){
            ope.push_back(make_pair(plus[0],minus[i]));
            plus[0]-=minus[i];
        }
        m=plus[0];
    }else{
        sort(all(plus));
        sort(rall(minus));
        for(int i=1;i<plus.size();i++){
            if(i<plus.size()-1){
                ope.push_back(make_pair(plus[0],plus[i]));
                plus[0]-=plus[i];
            }else{
                ope.push_back(make_pair(plus[i],plus[0]));
                plus[i]-=plus[0];
                m=plus[i];
            }
        }
        for(int i=1;i<minus.size();i++){
            ope.push_back(make_pair(minus[0],minus[i]));
            minus[0]-=minus[i];
            m=minus[0];
        }
    }
    out(m);
    rep(i,ope.size())out(ope[i].first,ope[i].second);
}