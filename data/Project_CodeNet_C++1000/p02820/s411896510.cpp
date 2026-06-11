#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int n,k,r,s,p;
    string t;
    cin >> n >> k;
    cin >> r >> s >> p;
    cin >>t;
    //rはグー、sはチョキ、pはパー
    long long int sum = 0;
    vector<bool> win(n,true);
    bool pre = false;//k個前で勝ってたならtrue
    for(int i=0;i<n;i++){
        if(win[i]){
            if(t[i]=='r'){//パーで勝つ
                sum += p;
            }
            if(t[i]=='s'){//グーでかつ
                sum += r;

            }
            if(t[i]=='p'){//チョキで勝つ
                sum += s;
            }
            if(i+k<n && t[i]==t[i+k]){
                win[i+k]=false;
            }
        }
        //cout << sum << endl;
    }
    cout << sum << endl;

}