#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<double> VL;
typedef vector<string> VS;
typedef vector<PLL> VP;
typedef vector<ll> VLL;
const static int INF = 1000000000;
const static int MOD = 1000000007;
#define rep(i,n) for (ll i=0; i<(ll)(n); i++)
#define repd(i,n) for (ll i=n-1; i>=0; i--)
#define rept(i,m,n) for(ll i=m; i<n; i++)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define PF push_front
#define PB push_back
#define SORT(V) sort((V).begin(), (V).end())
#define RVERSE(V) reverse((V).begin(), (V).end())
#define paired make_pair
#define PRINT(V) for(auto v : (V)) cout << v << " "
//charを整数に
int ctoi(char c) { if (c >= '0' && c <= '9') { return c - '0'; } return 0; }
// 累積和 for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i]; 
void cum_sum(int N,vector<double> a, vector<double> &s){ for(int i=0; i<N; i++){ s[i+1]=s[i]+a[i];}}
//ユークリッドの控除法
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
//最小公倍数
ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}
//空白文字も入力 getline(cin, S);
//桁数指定 setprecision

int main()
{
    string S;
    cin >> S;
    ll K;
    cin >> K;
    VC test(S.size()*2);
    rep(i,S.size()){
        test.at(i)=S.at(i);
    }
    for(int i=S.size(); i<S.size()*2; i++){
        test.at(i)=S.at(i-S.size());
    }
    ll sum=0;
    
    ll count=1;
    bool judge=true;
    rep(i,S.size()-1){
        if(S.at(i)!=S.at(i+1)){
            judge=false;
        }
    }
    if(judge){
        cout << S.size()*K/2 << endl;
        return 0;
    }

    rep(i,test.size()-1){
        if(test.at(i)==test.at(i+1)){
            count++;
            if(i==test.size()-2){
                sum+=count/2;
            }
            continue;
        }
        else{
            sum+=count/2;
        }
        count=1;
    }
    ll first_point=0;
    ll count_2=1;
    rep(i,S.size()-1){
        if(S.at(i)==S.at(i+1)){
            count_2++;
            if(i==S.size()-2){
                first_point+=count_2/2;
            }
            continue;
        }
        else{
            first_point+=count_2/2;
        }
        count_2=1;
    }
    ll dif=sum-first_point;
    cout << first_point+(K-1)*dif << endl;
}
