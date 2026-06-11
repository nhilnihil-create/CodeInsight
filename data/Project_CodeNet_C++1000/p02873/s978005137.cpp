#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i=0;i<(n);i++)

int main() {
    string S;
    cin>>S;
    vector<long long> left_count(S.size()+1,0);
    vector<long long> right_count(S.size()+1,0);
    long long count =0;
    rep(i,S.size()){
        if (S[i]=='<'){
            count++;
        }else{
            count =0;
        }
        left_count[i+1]=count;
    }

    count = 0;
    rep(j,S.size()){
        if (S[S.size()-1-j]=='>'){
            count++;
        }else{
            count = 0;
        }
        right_count[S.size()-1-j]=count;
    }
    long long ans =0;
    rep(k,S.size()+1){
        ans+=max(left_count[k],right_count[k]);
    }
    cout << ans << endl;
}

//18:00-18:38 miss1