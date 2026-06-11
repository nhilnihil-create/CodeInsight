 #include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}

bool flag = false;

/*
A:答えの配列
N:答えの文字列の長さ
max_:いままで出てきた数字の種類
vn:一個前に出た数字
*/
void dfs(vector<int> &A, int N, int max_, int vn) {
    if (A.size() == N) {
        //答えの出力
        for(int a : A) {
            //数字列を文字列に変換
            char s = 'a'+a;
            cout << s;
        }
        cout << endl;
        return;
    }
    //max_:いままで出てきたアルファベット+1種類しか出ないようにする変数
    //flag:一週目かどうかの判定
    if(max_ < vn+1 && flag) max_ = vn+1;
    
    //全探索
    for (int v = 0; v <= max_; ++v) {
        flag = true;
        A.push_back(v);
        dfs(A, N, max_, v);
        A.pop_back();
    }
}

int main(){
    int n;
    cin >> n;
    vi A;
    dfs(A, n, 0, 0);
    return 0;
}