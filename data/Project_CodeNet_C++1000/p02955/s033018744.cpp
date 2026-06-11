#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority_queue
#include<deque>//double_ended queue
using namespace std;
typedef pair<int,int> P;//Pでpair<-,->を表す。
typedef long long LL; 
LL MOD=1000000007;

/*ここから*/

vector<LL> d;
int D;//約数の個数
void divisor(LL x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){d.push_back(i);}
    }
    D=d.size();
    for(int i=D-1;i>=0;i--){
        if(d[i]*d[i]<x){d.push_back(x/d[i]);}
    }
    D=d.size();
}

/*ここまで*/

int main()
{ 
    LL n,K;
    cin>>n>>K;
    LL a[n];
    LL sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    //約数計算
    divisor(sum);
    //上から満たすか調べる。
    bool flg=true;
    LL ans=0;
    while(flg){
        LL x=d.back();
        d.pop_back();

        LL b[n];
        for(int i=0;i<n;i++){b[i]=a[i]%x;}
        sort(b,b+n);
        //累積和
        for(int i=1;i<n;i++){b[i]=b[i]+b[i-1];}
        int k=n-1-b[n-1]/x;
        if(b[k]<=K){flg=false;ans=x;}
    }
    cout<<ans<<endl;
    return 0;
}