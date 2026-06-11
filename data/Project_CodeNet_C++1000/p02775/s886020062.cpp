#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

//dp[i][j] i前の桁で繰り上がってる？ j j番目
lli dp[2][1000100];

void func(string &N){

    reverse(N.begin(),N.end());

    dp[0][0]=0;
    dp[1][0]=INF;

    REP(i,0,N.size()){
        //今回繰り上がらない

        lli num = N[i]-'0';
        dp[0][i+1] = min(dp[0][i]+num,dp[1][i]+num+1);

        //今回繰り上がる
        dp[1][i+1] = min(dp[0][i]+10-num,dp[1][i]+10-num-1);
    }

    REP(i,0,N.size()+1){
        LOG3(i,dp[0][i],dp[1][i]);
    }

    cout<<min(dp[0][N.size()],dp[1][N.size()]+1)<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    string N;
    cin>>N;
    func(N);
    return 0;
}
