
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//reverseはO(|s|)なので間に合わない
//先頭に追加もO(|S|)なのでダメ
//vectorを2つ用意し、reveseごとにその2つをswapする
int main(){
    string s;
    int q;
    cin >> s >> q;
    //これが2つ目のベクトル
    string t; 
    rep(qi,q){
        int ty;
        cin >> ty;
        if(ty==1){
            //swapはO(1)でできる
            swap(s,t);
        }
        else{
            int f; char c;
            cin >> f >> c;
            if(f==1){
                //先頭に追加=tに追加
                t += c;
            }
            else{
                //末尾に追加=sに追加
                s += c;
            }
        }
    }
    reverse(all(t));
    t += s;
    cout << t << endl;
    return 0;
}