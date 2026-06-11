#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

//二分探索
int binary_search(const vector<ll>& a ,ll key){
    int ng=-1, ok=(int)a.size();
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(a[mid] <= key){
            ng=mid;
        }else{
            ok=mid;
        }
    }
    return ng;
}

int main(){
    int N, M, K; cin>> N >> M >> K;

    int A, B;
    vector<ll> a(N + 1, 0), b(M + 1, 0);

    //Aの累積和
    rep(i, N){
        cin>> A;
        a[i + 1] = A + a[i];
    }

    //Bの累積和
    rep(i, M){
        cin>> B;
        b[i + 1] = B + b[i];
    }

    //Aを基準にして探索
    int ans = 0;
    int read_A;
    rep(i, N + 1){
        if(a[i] <= K) read_A = i;
        else read_A = 0;
        ans = max(ans, read_A + binary_search(b, K - a[i]));
    }

    cout<< ans << endl;
}
