#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int n;

void func(vector<int> vec){
    //bit列を表示させる
    for(int i=0;i<n;i++){
        cout << vec[i];
    }
    cout << endl;
    return;
}

int main() {
    //入力
    cin >> n;
    vector<vector<pair<int,int>>> pr(n);
    //証言
    rep(i,n){
      int j=0;
      int nn;
      cin >> nn;
      while(j<nn){
        int a,b;
        cin >> a >> b;
        a--;
        pr[i].push_back(make_pair(a,b));
        j++;
      }
    }

    //----- bit 全探索 ------
    //ここで2^n-1個のbit列を列挙
    int cnt=0;
    int nax = -1;
    for (int bit = 0; bit < (1 << n); ++bit) {
        cnt=0;
        vector<int> vec(n);
        //ここで、列の各位が1かをみる
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
            //もし1だったら何か処理
            vec[i]=1;
            }

        }
        //証言の照らし合わせ
        rep(i,n){
          bool flag = true;
          //仮定上、今見てる人が正しいならば
          if(vec[i]){
            //その人の証言に矛盾がないか確認
            rep(j,pr[i].size()){
              if(pr[i][j].second==1){
                if(vec[pr[i][j].first]==1);
                else flag = false;
              }
              if(pr[i][j].second==0){
                if(vec[pr[i][j].first]==1)
                  flag = false;
              }
            }
            if(flag) cnt++;
          }
        }
        int cnt2=0;
        rep(i,n){
          if(vec[i])
            cnt2++;
        }
        if(cnt==cnt2)
          nax = max(cnt,nax);
    }
    cout << nax << endl;
}
