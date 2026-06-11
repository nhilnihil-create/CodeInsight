#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

#define ALL(x) x.begin(),x.end()
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<int, vector<int>, greater<int> > gpq; //逆順priority_queue
typedef priority_queue<int> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;

int main(){
    int N,K;
    cin>>N>>K;
    vi A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    for(int j=0;j<K;j++){
        vi B(N,0);
        for(int i=0;i<N;i++){
            B[max(0,i-A[i])]++;
            if(i+A[i]+1<N)B[i+A[i]+1]--;
        }
        bool all_N=true;
        A[0]=B[0];
        if(A[0]<N)all_N=false;
        for(int i=1;i<N;i++){
            A[i]=A[i-1]+B[i];
            if(A[i]<N)all_N=false;
        }
        if(all_N)break;
    }

    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
}
