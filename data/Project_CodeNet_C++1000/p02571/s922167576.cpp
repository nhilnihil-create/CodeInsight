#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int INF = 1 << 30;

int f(string S,string T,int n){
    int cnt = 0;
    for(int i = 0;i < T.length();i++){
        if(S[n + i] != T[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string S,T;

    cin >> S >> T;

    int ans = INF;

    for(int i = 0;i <= S.length() - T.length();i++){
        ans = min(f(S,T,i),ans);
    }

    cout << ans << endl;

    return 0;
}
