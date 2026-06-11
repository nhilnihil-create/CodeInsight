#include <bits/stdc++.h>
#include <iostream>
#include <math.h>    //pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm> //sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init, i, n) for (ll i = init; i < (n); i++)
#define ll long long
#define rev(s) reverse(s.begin(), s.end())
#define sor(v) sort(v.begin(), v.end())
using namespace std;
//コード自動整形 Shift + Alt + F @vscode
ll bimin(ll);


/////main/////
int main()
{
    ll H, W, K, bc;
    cin >> H >> W >> K;
    vector<vector<char>> c(H, vector<char>(W));
    //cout<<"H="<<H<<endl;//
    //cout<<"W="<<W<<endl;//
    //cout<<"K="<<K<<endl;//
    bc = 0;
    rep(0, i, H)
    {
        rep(0, j, W)
        {
            cin >> c.at(i).at(j);

        }
    }

    /*rep(0, i, H)
    {
        rep(0, j, W)
        {
            cout << "c{"<<i<<","<<j<<"}=" << c.at(i).at(j)<<endl;;

        }
    }*/

    ll cnt = 0;
    ll tempi=0;
    ll tempj=0;
    rep(0,i,(1<<H)-1)rep(0,j,(1<<W)-1){
        tempi=i;
        tempj=j;
        rep(0,k,H)rep(0,m,W){
            if((tempi>>k & 1)==(ll)0 && (tempj>>m & 1)==(ll)0){
                if (c.at(k).at(m) == '#'){
                    bc += 1;
                }

            }
            tempi=i;
            tempj=j;

        }
        if(bc == K){cnt++;}
        bc = 0;
    }

cout<<cnt<<endl;

}




/////function/////


ll bimin(ll x){
//入力よりも大きい最小の2の累乗を返す
ll upper = 1;
rep(0,i,x){
    if(x<=upper){
        return upper;
    }else{
        upper *= 2;
    }
}
return 0;
}