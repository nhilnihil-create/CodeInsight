
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

//curという変数に「最後の壁から何マス来たのかを格納しておいて、iが壁なら0に戻し、iが通路ならお￥インクリメントする
//4方向分のcurの情報をleft,right,up,downに格納する
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];
int h, w;

int main(){
    
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);

    //前処理
    rep(i,h){
        int cur=0;
        rep(j,w){
            if(s[i][j] == '#') cur=0;
            else cur++;
            Left[i][j] = cur;
        }
    }
    rep(i,h){
        int cur=0;
        for(int j=w-1;j>=0;j--){
            if(s[i][j] =='#') cur=0;
            else cur++;
            Right[i][j] = cur;
        }
    }
    rep(j,w){
        int cur=0;
        rep(i,h){
            if(s[i][j]=='#') cur=0;
            else cur++;
            Up[i][j] = cur;
        }
    }
    rep(j,w){
        int cur=0;
        for(int i=h-1;i>=0;i--){
            if(s[i][j]=='#') cur=0;
            else cur++;
            Down[i][j]=cur;
        }
    }

    //集計
    int res=0;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#') continue; //壁に光源は置けないので無視
            res = max(res, Left[i][j]+Right[i][j] +Up[i][j] +Down[i][j]-3);
        }
    }
    cout << res << endl;

}