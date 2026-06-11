#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}

int dp[3010][3010][4];
int v[3010][3010]={};

signed main() {
    int N,K; cin>>N>>K;
    vector<int> p(N),c(N);
    rp(i,N) cin>>p[i],p[i]--;
    rp(i,N) cin>>c[i];

    int ans= -1e18;

    //各マスからスタートした場合を考える。
    rp(i,N){
        int v=i;
        int cycle_sum=0;
        int cycle_cnt=0;

        //そのマスからスタートして、サイクルの和とサイクルの要素数を求める。
        while(1){
            cycle_cnt++;
            cycle_sum+=c[p[v]];
            v=p[v];
            if(v==i) break;
        }

        int path=0;
        int cnt=0;

        //そのマスからスタートして、各マスで終わった場合のスコアを求める。
        while(true){
            cnt++;
            path+=c[p[v]];

            if(cnt>K) break;

            //numは追加で訪れる回数。サイクルの和が正ならばその分だけ追加する。
            int num = (K-cnt) / cycle_cnt;
            int score = path + max(0LL,cycle_sum)*num;
            chmax(ans,score);

            v=p[v];
            if(v==i) break;
        }
    }

    cout<<ans<<endl;
}
