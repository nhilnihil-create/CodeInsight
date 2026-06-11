#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int main() {
    string S;
    cin>>S;
    int cnt_even=0, cnt_odd=0;
    vi ans(S.size(),0);
    for (int i = 0; i < S.size(); i++){
        if(S[i]=='R'){
            if(i%2==0)cnt_even++;
            else cnt_odd++;
        }else{
            if(i%2==0){
                ans[i]+=cnt_even;
                ans[i-1]+=cnt_odd;
            }else{
                ans[i]+=cnt_odd;
                ans[i-1]+=cnt_even;
            }
            cnt_even=0;
            cnt_odd=0;
        }
    }
    for (int i = S.size()-1; i>=0; i--){
        if(S[i]=='L'){
            if(i%2==0)cnt_even++;
            else cnt_odd++;
        }else{
            if(i%2==0){
                ans[i]+=cnt_even;
                ans[i+1]+=cnt_odd;
            }else{
                ans[i]+=cnt_odd;
                ans[i+1]+=cnt_even;
            }
            cnt_even=0;
            cnt_odd=0;
        }
    }
    for(auto x:ans)cout<<x<<" ";
    cout<<endl;
}