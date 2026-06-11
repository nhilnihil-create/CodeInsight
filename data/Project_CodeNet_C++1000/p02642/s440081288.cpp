#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
//Not Divisible
int main()
{
    int MAX = -1;
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N){
       cin >> A[i]; 
       chmax(MAX, A[i]);
    }
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }

    vector<int> s(MAX+5, 0);
    rep(i, N)
    {
        for(int j = 1 ; A[i]*j <= MAX; ++j)
        {
            //if(!is_prime[j]) continue;
            s[A[i]*j]++;
        }
    }
    int ans = 0;
    rep(i, N)
    {
        if(s[A[i]] <=1)
        {
            //cout << A[i] << endl;
            ++ans;
        } 
        
    }
    cout << ans << endl;

    return 0;
}
#if 0
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(ALL(A));
    reverse(ALL(A));
    //rep(i, N) cout << A[i] << " ";
    int cnt = 0;
    rep(i, N-1)
    {
        bool b = true;
        rep2(j, i+1, N)
        {
            if(A[i]%A[j] == 0){
                b = false;
                //cout << i << "," << j << endl;
                break;
            }
        } 
        if(b) cnt++;
    }
    bool b = true;
    rep(i, N-1)
    {
        if(A[N-1]%A[i] == 0){
            b = false;break;
        }
    }
    if(b) cnt++;
    cout << cnt << endl;
    return 0;
}
#endif