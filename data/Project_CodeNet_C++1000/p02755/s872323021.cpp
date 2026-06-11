#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int a,b;cin>>a>>b;
    for(int i =0;i<10000;i++){
        int t8 =i*0.08;
        int t10=i*0.1;
        if(t8==a&&b==t10){
            cout<<i<<endl;
            return 0;
        }

    }

    cout<<-1<<endl;


}