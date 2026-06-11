#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
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

vector<long long int> fibo(100001,-1);
long long int fibonatti(long long int n){
    if(fibo[n]!=-1){
        return fibo[n];
    }else if(n==0){
        fibo[0]=1;
        return 1;
    }else if(n==1){
        fibo[1]=1;
        return 1;
    }else if(n>=2){
        fibo[n]=(fibonatti(n-1)+fibonatti(n-2))%MOD;
        return fibo[n];
    }
}
 
int main(){
    ll n,m;
    in(n,m);
    vector<int> vec(m);
    in(vec);
    fibonatti(100000);
    vec.push_back(n+1);
    ll target=0,ans=1,d=0;
    rep(i,m+1){
        if(i==0)target=vec[i]-1;
        else target=vec[i]-vec[i-1]-2;
        if(target==-1){
            ans=0;
            break;
        }
        d=0;
        if(target==0)d=1;
        else if(target==1)d=1;
        else if(target==2)d=2;
        else if(target>=3){
            d=fibo[target];
        }
        ans*=d;
        if(ans>MOD)ans%=(ll)MOD;
    }
    out(ans);
}
