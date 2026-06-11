#include <bits/stdc++.h>
using namespace std;

int c[10][10];
int main(){
    int n;
    cin >> n;
    int ans=0;
    string S;
    for(int i=1;i<=n;i++){
        S=to_string(i);
        c[S[0]-'0'][S[S.length()-1]-'0']++;
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            ans+=c[i][j]*c[j][i];
        }
    }
    cout << ans << endl;
}