#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int n,m,q,mx_sum;
vector<int> a,b,c,d;

void dfs(vector<int> A){
   if(A.size() == n+1){
       int sum = 0;
       rep(i,q){
           if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
       }
       mx_sum = max(sum, mx_sum);
       return;
   }
   //同じかそれ以上を追加する
   A.pb(A.back());
   while(A.back() <= m){
       dfs(A);
       A.back()++;
   }

}

int main()
{
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    //数列を作る。得点を出す。最大を出す。
    dfs(vector<int> (1,1));
    cout << mx_sum << endl;
    return 0;
}

/*
g++ c.cpp
./a.out

oj d https://atcoder.jp/contests/abc169/tasks/abc169_b
oj t
*/
