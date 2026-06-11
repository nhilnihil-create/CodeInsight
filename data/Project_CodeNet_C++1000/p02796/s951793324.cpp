#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int n,x,l;
int ans =0;

int main(){
    cin >> n;
    pair<int,int> rob[n];
    rep(i,n){
        cin >> x >> l;
        rob[i].first = x +l; // ロボの範囲の終了地点
        rob[i].second = x -l; // ロボの範囲の開始地点
    }
    sort(rob, rob+n); //終了地点が小さい順に並べる
    int t = -100000000; //今見ている地点
    rep(i,n){
        if(rob[i].second >= t){
            t = rob[i].first;
            ans +=1;
        }
    }

    cout << ans <<endl;
}