#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int N,cnt = 0;
    while(cin >> N){
        for(int i = 0;i <= 9;i++)for(int j = 0;j <= 9;j++)for(int k = 0;k <= 9;k++)
        if(N-i-j-k >= 0 && N-i-j-k <= 9)cnt++;
        cout << cnt << endl;
        cnt = 0;
    }
}