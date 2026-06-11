/*
author : seryu
title : ABC176E_"Bomber"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define mrep(i,j,n) for(int i = j; i < n; i++)
#define mreps(i,j,n) for(int i = j; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

//vector<pair<int,int>>の比較関数
bool compare_by_second(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)return a.first < b.first;
    else return a.second < b.second;
}

void solve()
{
    int h, w, m;
    cin >> h >> w >> m;
    vector<P> r_sum, c_sum;
    rep(i, h)r_sum.push_back({0, i});
    rep(i, w)c_sum.push_back({0, i});
    vector<P> obj;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        obj.push_back({a, b});
        r_sum[a].first++;
        c_sum[b].first++;
    }
    sort(all(obj));
    sort(all(r_sum));
    reverse(all(r_sum));
    sort(all(c_sum));
    reverse(all(c_sum));
    int ans = 0;
    int i_r = 0, i_c = 0;
    int last_r = r_sum[i_r].first, last_c = c_sum[i_c].first;
    while (true)
    {
        int tmp = last_r + last_c;
        int r = r_sum[i_r].second;
        int c = c_sum[i_c].second;
        
        bool cross = [&]{
            int left = 0, right = m;
            while (left <= right)
            {
                int mid = (left+right)/2;
                if (obj[mid].first == r && obj[mid].second == c)return true;
                else if(obj[mid].first < r) left = mid+1;
                else if(obj[mid].first > r) right = mid-1;
                else if(obj[mid].second < c)left = mid+1;
                else right = mid-1;
            }
            return false;
        }();

        if(cross)tmp--;
        chmax(ans, tmp);
        if (i_r+1 < h && r_sum[i_r+1].first == last_r)
        {
            i_r++;
        }
        else if (i_c+1 < w && c_sum[i_c+1].first == last_c)
        {
            i_c++;
        }
        else
        {
            break;
        }        
    }
    cout << ans << endl;
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
