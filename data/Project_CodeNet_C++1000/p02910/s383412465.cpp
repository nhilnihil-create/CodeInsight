#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll C[2005][2005];
ll dp[100005][13];

int main(){
    int a,N,ans=0;
    string S;
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(i%2 == 0){
            if(S[i] == 'R' || S[i] == 'U' || S[i] == 'D')continue;
            else ans = -1;
        }else{
            if(S[i] == 'L' || S[i] == 'U' || S[i] == 'D')continue;
            else ans = -1;
        }
    }
    if(ans == -1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}