#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

#define ALL(x) x.begin(),x.end()
#define get_tp(t,i) get<i>(t)
#define len(x) (ll)(x.size())
#define ub(a,x) (upper_bound(ALL(a),x)-a.begin())
#define lb(a,x) (lower_bound(ALL(a),x)-a.begin())
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef pair<long long,long long> pllll; //pair<ll,ll>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<int, vector<int>, greater<int> > gpq; //逆順priority_queue
typedef priority_queue<int> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;

int main(){
    int N;
    cin>>N;
    vi a(N+1);
    vi ans(N+1,-1);
    for(int i=1;i<=N;i++)cin>>a[i];
    for(int i=N;i>=1;i--){
        int count=0;
        for(int j=i*(N/i);j>i;j-=i){
            if(ans[j]==1)count++;
        }
        if((a[i]+count)%2){
            ans[i]=1;
        }else{
            ans[i]=0;
        }
    }
    vi b(0);
    for(int i=1;i<=N;i++){
        if(ans[i]==1)b.push_back(i);
    }
    cout<<b.size()<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i];
        if(i<b.size()-1){
            cout<<" ";
        }else{
            cout<<endl;
        }
    }
}
