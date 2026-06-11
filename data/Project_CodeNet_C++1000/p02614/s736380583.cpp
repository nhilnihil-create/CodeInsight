#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int H,W,K;
    cin>>H>>W>>K;
    vector<vector<char>>c(H, vector<char>(W));//操作に用いる二次元はいれつ
    int bcount=0;
    int counter=0;
    int b=0;
    rep(i,H){
        rep(j,W){
            cin>>c.at(i).at(j);
            if(c.at(i).at(j)=='#'){
                b++;
            }
        }
    }
    for(int t1=0;t1<(1<<H);t1++){
        for(int t2=0;t2<(1<<W);t2++){
            bitset<6>s1(t1);//gyou
            bitset<6>s2(t2);//retsu
            bcount=b;//黒の数を選択前にする
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    if(s1.test(i)||s2.test(j)){
                        if(c.at(i).at(j)=='#'){
                            bcount--;
                        }
                    }
                }            
            }
            if(bcount==K){//黒であればcounterに数える
                counter++;
            }
        }
    }
    cout<<counter<<endl;    
}