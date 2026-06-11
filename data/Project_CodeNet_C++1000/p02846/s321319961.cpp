#include <iostream>
#include <algorithm>
#include <vector> //動的配列
#include <string>
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <numeric>
#include <tuple>



typedef long long ll;


using namespace std;

typedef pair<int, int> P;
#define FOR(i,a,b) for(int i=(int)(a) ; i < (int) (b) ; ++i )
#define rep(i,n) FOR(i,0,n)
#define sz(x) int(x.size())


template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

//小さい順から取り出すヒープ
//priority_queue<ll, vector<ll>, greater<ll> > pque1;




int main(){
    int t1,t2;
    ll a1,a2,b1,b2;
    ll da1,da2,db1,db2,d1,d2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    da1=a1*t1;da2=a2*t2;
    db1=b1*t1;db2=b2*t2;
    d1=da1-db1;d2=da2-db2;
    ll ans=0;
    if (d1<0){
        if (d2+d1==0){
            printf("infinity");
            return 0;
        }else if (d1+d2<0){
            cout<<0;
            return 0;
        }else{
            if (-d1%(d2+d1)==0){
                ans+=2*-d1/(d2+d1);
            }else {
                ans+=2*(-d1/(d2+d1));
                ans++;
            }
        }
        
    }else {
        d1*=-1;
        d2*=-1;
        if (d2+d1==0){
            printf("infinity");
            return 0;
        }else if (d1+d2<0){
            cout<<0;
            return 0;
        }else{
            if (-d1%(d2+d1)==0){
                ans+=2*-d1/(d2+d1);
            }else {
                ans+=2*(-d1/(d2+d1));
                ans++;
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
