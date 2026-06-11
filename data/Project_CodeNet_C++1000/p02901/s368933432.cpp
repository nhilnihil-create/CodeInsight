#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>
#include <numeric>

using namespace std;

#define INT_MAX_VALUE 2147483647
#define LONG_LONG_MAX_VALUE 9223372036854775807
#define ll long long
#define ld long double

struct XX{
    ll cost;
    ll a;
    ll f;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.cost) == (riRight.cost)){
            return riLeft.f < riRight.f;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.cost) < (riRight.cost);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}

//int n;
////int dat[2*10000000];
////int dat2[2*10000000];
//int dat[10];
//int dat2[10];
//
//void init(int n_){
//    n=1;
//    while(n<n_)n*=2;
//    for(int i=0;i<2*n-1;i++){
//        dat[i]=0;
//        dat2[i]=0;
//    }
//}
//
//void initset(int k,int a){
//    k+=n-1;
//    dat[k]=a;
//    while(k>0){
//        k=(k-1)/2;
//        dat[k]=dat[k*2+1]+dat[k*2+2];
//    }
//}
//
////[a,b)の間を[l,r]区間で比較しアップデート
////引数のindexに注意
////nは固定。initで計算すみ
////update2(L[i],R[i]+1,0,0,n,D[i]);
//void update2(int a,int b,int k,int l,int r,int v){//v更新値、区間は0-index
//    if(r<=a || b<=l)return;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=v*(r-l);
//        return;
//    }else{
//        update2(a,b,k*2+1,l,(l+r)/2,v);
//        update2(a,b,k*2+2,(l+r)/2,r,v);
//        return;
//    }
//}
//
//int query(int a,int b,int k,int l,int r){
//    if(r<=a || b<=l)return 0;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=0;
//        return dat[k];
//    }
//    else{
//        int vl=query(a,b,k*2+1,l,(l+r)/2);
//        int vr=query(a,b,k*2+2,(l+r)/2,r);
//        return vl+vr;
//    }
//}



//void printb(unsigned int v) {
//    unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
//    do putchar(mask & v ? '1' : '0');
//    while (mask >>= 1);
//}


#ifdef DEBUG
ll dp[10][1000];
ll a[10];
ll c[1000];
#else
ll dp[1000][4100];//i個鍵を選んだ時のj箱が空いている状態
ll a[1000];
ll c[4100];
#endif


int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("a.txt");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int b;
        cin>>a[i]>>b;
        for(int j=0;j<b;j++){
            int tmp;
            cin>>tmp;
            c[i]+=pow(2,tmp-1);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<4100;j++){
            dp[i][j]=INT_MAX_VALUE;
        }
    }
    dp[0][c[0]]=a[0];
    for(int i=1;i<M;i++){
        dp[i][c[i]]=a[i];
        for(int j=0;j<4100;j++){
            if(dp[i-1][j]!=INT_MAX_VALUE){
                dp[i][j|c[i]]=min(dp[i][j|c[i]],dp[i-1][j]+a[i]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }
    }
    ll t=pow(2,N)-1;
    if(dp[M-1][t]!=INT_MAX_VALUE){
        cout << dp[M-1][t] << endl;
    }else{
        cout << -1 << endl;
    }
    
    //ここまで
    //cout << " " << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
