#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    ll S(0);
    rep(i,N){
        cin >> A[i];
        S += A[i];
    }
    vector<ll> d;//答えの候補
    for(int i=1;i*i<=S;i++){
        if(S%i==0){
            d.push_back(i);
            d.push_back(S/i);
        }
    }
    int M = d.size();//答えの候補の数
    vector<ll> a(N);//Aの各要素をdで割った余りの集合
    ll a_sum,sum_left,sum_right,target_d,d_max(0);
    for(int i=0;i<M;i++){
        target_d = d[i];//target_dが達成可能かどうかを調べる
        a_sum = 0;//Aの各要素をtarget_dで割った余りの集合の総和
        for(int j=0;j<N;j++){
            a[j] = A[j] % target_d;
            a_sum += a[j];
        }
        sort(ALL(a));
        //余りの集合を昇り順にソートする
        sum_left = a_sum;
        sum_right = 0;
        ll swap_num = 1e18;
        for(int j=N-1;j>=0;j--){
            sum_left -= a[j];//配れる回数
            sum_right += target_d - a[j];//必要な回数
            if(abs(sum_left - sum_right) % target_d == 0) swap_num = min(swap_num,max(sum_left,sum_right));
        }
        if(swap_num <= K )d_max = max(d_max,target_d);
    }
    cout << d_max << endl;
}