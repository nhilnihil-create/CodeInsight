#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=1'000'000'007;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////
void answer(){
    unsigned long long H, W;
    cin>>H>>W;
    vector<string> HW(H);
    for(auto &s : HW){
        cin>>s;
    }

    vector<vector<int>> dp(H, vector<int>(W, INF));
    if(HW[0][0] == '#'){
        dp[0][0] = 1;
    }else{
        dp[0][0] = 0;
    }
    debug(dp[0][0]);
    for(int i=1; i<H; ++i){
        if(HW[i-1][0] == '.' && HW[i][0] == '#'){
            dp[i][0] = dp[i-1][0] + 1;
            debug(dp[i][0]);
        }else{
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int j=1; j<W; ++j){
        if(HW[0][j-1] == '.' && HW[0][j] == '#'){
            dp[0][j] = dp[0][j-1] + 1;
            debug(dp[0][j]);
        }else{
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i=1; i<H; ++i){
        for(int j=1; j<W; ++j){
            int down_cost = 0;
            int right_cost = 0;
            if(HW[i-1][j] == '.' && HW[i][j] == '#'){
                right_cost++;
            }
            if(HW[i][j-1] == '.' && HW[i][j] == '#'){
                down_cost++;
            }
            dp[i][j] = min(dp[i-1][j]+right_cost, dp[i][j-1]+down_cost);
            debug(dp[i][j]);
        }
    }

    cout<<dp[H-1][W-1]<<endl;

    return;
}
/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    answer();

    return 0;
}
