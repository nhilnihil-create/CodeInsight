#define _GLIBCXX_DEBUG
#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using Mat = vector<vector<int>>;

// /*
int main(){
    int n;
    cin >> n;
    vi a(n);
    Mat x(n),y(n);
    rep(i,n){
        cin >> a[i];
        rep(j,a[i]){
            int x_,y_;
            cin >> x_ >> y_;
            x[i].push_back(x_);
            y[i].push_back(y_);
        } 
    }

    int max_honest = 0; 
    for(int t=0; t<(1<<n); ++t){
        bitset<16> s(t);
        int num_honest = 0;
        bool can = true;
        rep(i,n){//N人を検証
            rep(j,a[i]){//一人当たりの証言
                //正直者だと仮定した人の証言検証
                if(s.test(i)&&(s.test(x[i][j]-1)!= y[i][j])){
                    can = false;
                    break;
                }
                //嘘つきだと仮定した人の証言検証
                // if(!(s.test(i))&&(s.test(x[i][j]-1) == y[i][j])){
                //     can = false;
                //     break;
                // }
            }
            if(can && s.test(i)) num_honest += 1;
            if(can==false) break;
        }
        if(can && num_honest>max_honest) max_honest = num_honest;
    }
    cout(max_honest);
    
    return 0;
}
// */
