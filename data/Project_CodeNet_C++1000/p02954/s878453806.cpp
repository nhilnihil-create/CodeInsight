#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    string s;
    cin >> s;
    vector<int> ans(s.size());
    int sPoint = 0, even = 1, odd = 0;
    for(int i = 1; i < s.size(); i++){
        if( (s[i-1] == 'L' && s[i] == 'R')){
            if (sPoint % 2 == 0){
                ans[sPoint] = even;
                ans[sPoint-1] = odd;
            } else{
                ans[sPoint] = odd;
                ans[sPoint-1] = even;
            }
            even = odd = 0;
        }
        if ( s[i-1] == 'R' && s[i] == 'L' ){
            sPoint = i;
        }
        if(i % 2 == 0){
            even++;
        }else{
            odd++;
        }
    }
    if (sPoint % 2 == 0){
        ans[sPoint] = even;
        ans[sPoint-1] = odd;
    }else{
        ans[sPoint] = odd;
        ans[sPoint-1] = even;
    }

    rep(i, s.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}