#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    vector<int> a(N+1,-1);
    long long large_count = 0;
    long long small_count = 0;
    char before = S[0];
    int target_index = 0;
    rep(i, N){
        char now = S[i];

        if(before == '<' && now == '>'){
            target_index = i;
        }else if ( before == '>' && now == '<' ){
            a[target_index] = max({large_count, small_count});
            if(a[target_index] == large_count){
                a[target_index + 1] = small_count - 1;
            }
            a[i] = 0;
            large_count = 0;
            small_count = 0;
        }else if( now == '>' && i == (N-1) ){
            a[target_index] = max({large_count, small_count + 1});
            if(a[target_index] == large_count){
                a[target_index + 1] = small_count - 1;
            }
        }

        if(now == '<'){
            large_count+=1;
        }else{
            small_count+=1;
        }

        before = now;
    }

    before = S[0];
    if(a[0]==-1)a[0]=0;
    rep(i, N){
        char now = S[i];
        if(now == '<' && a[i+1] == -1){
            a[i+1] = a[i] + 1;
        }
        if(now == '>'&& a[i+1] == -1){
            a[i+1] = a[i] - 1;
        }
    }

    long long ans = 0;
    rep(i, (N+1)){
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}