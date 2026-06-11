#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;

//status unsolved
long long ans=0;
long long tens[6]={1,10,100,1000,10000,100000};
bool check(long long b,long long n){

    long long p=b;
    int size=0;
    while(p>0){
        p/=10;
        size++;
    }
    p=0;
    rep(i,size){
        p+=(b%10)*tens[size-1-i];
        b/10;
    }
    if(p<=n)return true;

    else{
        return false;
    }
    
}

int head(long long p){
    int now=0;
    while(p>0){
        now=p%10;
        p/=10;
    }
    return now;
}

int tail(long long p){
    return p%10;
}
int main(){
    long long n;
    cin>>n;
    long long ans=0;

    long long cnt[10][10]={};
    /*
        1<=x<=Nを満たす各xについて
        h=先頭の数字
        t=最後尾の数字として
        cnt[i][k]:=先頭がi桁で始まり、最後がkで終わる数字数として

        i=1~9,k=1~9の範囲で足し合わせる
        
        ans+=c[i][k]*c[k][i];
        
        */
    for(long long p=1;p<=n;p++){
        
        int h=head(p);
        int t=tail(p);
        cnt[h][t]++;
    }
    rep(i,10)rep(k,10)ans+=cnt[i][k]*cnt[k][i];

    cout<<ans<<endl;

    return 0;

}
/*


*/
