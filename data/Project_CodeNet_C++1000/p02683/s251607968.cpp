#include<iostream>
#include<vector>
using namespace std;

int n,m,x;
int c[12];
int a[12][12];

int main(){
    /*入力*/ 
    cin >> n >> m >> x;
    for(int i = 0;i < n;i++){
        cin >> c[i];
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
        }
    }
    /**/

    int ans = INT_MAX;

    for (int bit = 0; bit < (1<<n); ++bit)
    {
        // bit の表す集合を求める
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // i が bit に入るかどうか
                S.push_back(i);
            }
        }

        int rikai[12] = {0};
        int sans = 0;

        //各アルゴリズムにc[S.front()]をたす
        while(!S.empty()) {
            //cout << S.front() << " ";
            
            sans += c[S.front()];
            for(int i = 0;i < m;i++){
                rikai[i] += a[S.front()][i];
            }
            S.erase(S.begin());
        }
        
        //全てのアルゴリズムがx以上の理解度をえられたら,
        int count = 0;
        for(int i = 0;i < m;i++){
            //cout << rikai[i] << " " << x << endl;
            if(rikai[i] >= x){
                count++;
            }
        }
        
        //最小コストを求める
        if(count == m){
            ans = min(ans , sans);
        }
    }

    
    if(ans == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    


    return 0;
}