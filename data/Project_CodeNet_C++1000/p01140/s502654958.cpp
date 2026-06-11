// 問題名:　Square Route
// URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2015&lang=jp
// 所要時間: 20分
// --感想--
// intの配列は今までfor文を用いて1個ずつ0を代入して初期化していたので、今後は"= {}"などを用いて簡略化するようにしたい。

#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n, m, h[1555], w[1555];
        cin >> n >> m;
        if(n==0)
            break;
        for (int i = 0; i < n;i++)
            cin >> h[i];
        for (int i = 0; i < m;i++)
            cin >> w[i];
        // 間隔がdとなるような東西/南北方向の道2つの組み合わせの数
        int count_h[1500010] = {}, count_w[1500010] = {};
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i;j<n;j++){
                sum += h[j];
                count_h[sum]++;
            }
        }
        for (int i = 0; i < m; i++){
            int sum = 0;
            for (int j = i; j < m; j++){
                sum += w[j];
                count_w[sum]++;
            }
        }
        int ans = 0;
        for (int i = 1; i < 1500010;i++)
            ans += count_h[i] * count_w[i];
        cout << ans << endl;
    }
}
