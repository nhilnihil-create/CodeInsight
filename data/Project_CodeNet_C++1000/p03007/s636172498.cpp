#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
#define ld long double
int main(){
    int n;
    cin>>n;
    int64_t sum=0;
    vector<int64_t> a(n);
    rep(i,n){
        cin>>a[i];
        sum += a[i];
    }
    all(a);
    if(n==2){
        cout<<a[1]-a[0]<<endl;
        cout<<a[1]<<" "<<a[0]<<endl;
        return 0;
    }

    //a1+a2+a3+.....+anの中から「1個以上n-1個未満」マイナスにする
    if(a[0]>0){//1個目だけ-にする
        int64_t ans = sum-2*a[0];
        cout<<ans<<endl;
        int halfway=a[0];
        rep(i,n-1){
            if(i==n-2){
                cout<<a[i+1]<<" "<<halfway<<endl;
            }
            else{
                cout<<halfway<<" "<<a[i+1]<<endl;
                halfway -= a[i+1];
            }
        }
    }
    else if(a[n-1]<=0){//a[n-1]以外全部マイナスにする
        int64_t ans = -sum + 2*a[n-1];
        cout<<ans<<endl;
        int halfway = a[n-1];
        rep(i,n-1){
            cout<<halfway<<" "<<a[i]<<endl;
            halfway -= a[i];
        }
    }
    else{//正の数なら+に、負の数ならマイナスにする
        int64_t ans=0;
        rep(i,n){
            ans += abs(a[i]);
        }
        cout<<ans<<endl;
        int halfway = a[0];
        rep(i,n){
            if(a[i]>0 && i!=n-1){
                cout<<halfway<<" "<<a[i]<<endl;
                halfway -= a[i];
            }
        }
        int plushalf = a[n-1];
        rep(i,n){
            if(i!=0 && a[i]<=0){
                cout<<plushalf<<" "<<a[i]<<endl;
                plushalf -= a[i];
            }
        }
        cout<<plushalf<<" "<<halfway<<endl;
    }
}