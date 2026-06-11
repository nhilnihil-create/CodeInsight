#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
int N,d;
vi NV;
int main() {
    cin>>N;
    vector<vi> memo(10,vi(10,0));
    for (int i = 1; i < N+1; i++){
        string s=to_string(i);
        int l=(int)s[0]-(int)'0';
        int r=(int)s[s.size()-1]-(int)'0';
        memo[l][r]++;
    }
    int ans=0;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            ans+=memo[i][j]*memo[j][i];
        }
    }
    cout<<ans<<endl;
}