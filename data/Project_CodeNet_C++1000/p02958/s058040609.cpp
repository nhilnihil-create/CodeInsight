#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p.at(i);
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            vector<int> t = p;
            swap(t.at(i),t.at(j));
            bool is_syoujun = true;
            rep(k,n-1){
                if(t.at(k) > t.at(k+1)) is_syoujun = false;
            }
            if(is_syoujun){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}