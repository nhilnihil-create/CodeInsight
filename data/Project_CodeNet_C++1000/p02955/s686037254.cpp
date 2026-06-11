#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


void yakusu(int num, vector<int>& yaku){
    yaku.push_back(1);
    for (int i = 2; i*i <= num; i++)
    {
        if (num%i == 0) {
            yaku.push_back(i);
            if (i*i != num) yaku.push_back(num/i);
        } 
    }
    yaku.push_back(num);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int sum = 0;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp); sum+=tmp;}
    vector<int> yaku;
    yakusu(sum, yaku);
    sort(yaku.begin(), yaku.end());
    //show(yaku);
    int t_ans;
    int s = yaku.size();
    for (int i = s-1; i >= 0; i--)
    {
        int ans = 0;
        vector<int> y_len(n);
        rep(j, n){
            y_len[j] = a[j]%yaku[i];
        }
        sort(y_len.begin(), y_len.end());
        vector<int> y_len_sum(n+1, 0);
        vector<int> y_len_sum_inv(n+1, 0);
        rep(j, n){
            y_len_sum[j+1] += y_len[j] + y_len_sum[j];
        }
        rep(j, n){
            y_len_sum_inv[n-1-j] += (yaku[i] - y_len[n-1-j]) + y_len_sum_inv[n-j];
        }
        // cout << yaku[i] << endl;
        // show(y_len);
        // show(y_len_sum);
        // show(y_len_sum_inv);

        rep(j, n){
            if (y_len_sum[j] == y_len_sum_inv[j]) {ans = y_len_sum[j]; break;}
        }
        if (ans <= k){
            t_ans = yaku[i];
            break;
        }
    }
    cout << t_ans << endl;
}

