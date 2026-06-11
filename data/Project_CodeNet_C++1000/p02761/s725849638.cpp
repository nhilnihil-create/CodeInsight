#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> s(M);
    vector<int> c(M);
    rep(i,M){
        cin >> s[i] >> c[i];
    }

    vector<int> vals(N, -1);
    rep(i,M){
        int target_digit = s[i] - 1;
        int val = c[i];

        if(vals[target_digit]==-1 || vals[target_digit]==val){
            vals[target_digit] = val;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }

    if(vals[0]==0 && N>1){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;

    if(N==1){
        if(vals[0]!=-1){ans = vals[0];}
    }else{
        rep(i,N){
            if(i!=0){
                if(vals[i]==-1){vals[i]=0;}
            }else{
                if(vals[i]==-1){vals[i]=1;}
            }
            ans += vals[i] * round(pow(10,N-1-i));
        }
    }

    cout << ans << endl;
    return 0;

}