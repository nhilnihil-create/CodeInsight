#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}

template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll long long 
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
ll status[1000005];
void siv(){
    ll N = 1000000;
    ll i, j;
    for (i = 2; i <= N;i++){
        if(status[i]==0){
            status[i] = i;
            for (j = i * i; j <= N; j += i){
                if(status[j]==0){
                    status[j] = i;
                }
            }
        }
    }
    status[1] = 1;
}
ll fre[1000005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    siv();
    ll i,j,k,l,n,m;
    cin>>n;
    ll data[n + 1];
    for (i = 1; i <= n;i++)
        cin >> data[i];
    ll GCD = 0;
    for (i = 1; i <= n;i++){
        ll temp = data[i];
        GCD = __gcd(temp, GCD);
        ll pre = -1;
        while(temp!=1){
            if(pre!=status[temp]){
                pre = status[temp];
                fre[pre]++;
            }
            temp /= status[temp];
        }
    }
    if(GCD!=1){
        cout << "not coprime\n";
    }
    else{
        ll cnt = 0;
        for (i = 1; i <= 1000000;i++){
            if(fre[i]>1)
                cnt++;
        }
        if(cnt>=1){
            cout << "setwise coprime\n";
        }
        else
            cout << "pairwise coprime\n";
    }
    return 0;
}
