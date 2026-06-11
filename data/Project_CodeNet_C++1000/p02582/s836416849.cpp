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

int main(){
    string S;

    cin >> S;

    int cnt = 0;
    int ans = 0;
    
    for(int i = 0;i < S.length();i++){
        if(S[i] == 'R'){
            cnt++;
        }else{
            cnt = 0;
        }
        ans = max(ans,cnt);
    }

    cout << ans << endl;

    return 0;
}