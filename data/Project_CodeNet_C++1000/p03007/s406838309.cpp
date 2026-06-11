#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

// pairsをsecond優先キーとして昇順ソート
bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    vector<P> plus;
    vector<P> minus;
    vector<P> zero;

    ll pcount = 0;
    ll mcount = 0;

    REP(i, N){
        P p;
        p.first = i;
        cin >> p.second;
        if(p.second >= 0){
            plus.push_back(p);
            pcount++;
        }
        if(p.second < 0){
            minus.push_back(p);
            mcount++;
        }
    }

    sort(plus.begin(), plus.end(), compare_by_b);
    sort(minus.begin(), minus.end(), compare_by_b);

    ll max = 0;
    ll min = 0;

    vector<P> ans;

    if(pcount>0 && mcount>0){
        max = plus[pcount-1].second;
        for(ll i=1; i<mcount; i++){
            // cout << max << " " << minus[i].second << endl;
            P temp;
            temp.first = max;
            temp.second = minus[i].second;
            ans.push_back(temp);
            max = max - minus[i].second;
        }

        min = minus[0].second;
        for(ll i=0; i<pcount-1; i++){
            // cout << min << " " << plus[i].second << endl;
            P temp;
            temp.first = min;
            temp.second = plus[i].second;
            ans.push_back(temp);
            min = min - plus[i].second;
        }

        P temp;
        temp.first = max;
        temp.second = min;
        ans.push_back(temp);
        max = max - min;
    }

    if(pcount == 0 && mcount>0){
        max = minus[mcount-1].second;
        for(ll i=0; i<mcount-1; i++){
            P temp;
            temp.first = max;
            temp.second = minus[i].second;
            ans.push_back(temp);
            max = max - minus[i].second;
        }
    }
if(pcount > 0 && mcount == 0){
        min = plus[0].second;
        max = plus[pcount-1].second;
        for(ll i=1; i<pcount-1; i++){
            P temp;
            temp.first = min;
            temp.second = plus[i].second;
            ans.push_back(temp);
            min = min - plus[i].second;
        }
        P temp;
        temp.first = max;
        temp.second = min;
        ans.push_back(temp);
        max = max - min;
    }

    cout << max << endl;
    for(auto v: ans){
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}