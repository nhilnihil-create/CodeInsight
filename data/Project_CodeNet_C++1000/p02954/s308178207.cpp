#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s; cin >> s;
    int n = 0; n = s.length();

    vector<ll> ans(n, 0);

    ll rl_left = 0, rl_right = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='R' && s[i+1]=='L'){
            ans[i]=1; ans[i+1]=1;
            for(int j=i-1; j>=0; j--){
                if(s[j]=='L'){
                    break;
                }else if(s[j]=='R'){
                    if((j - i)%2==0){
                        ans[i]++;
                    }else{
                        ans[i+1]++;
                    }
                }
            }
            for(int k=i+2; k<n; k++){
                if(s[k]=='R'){
                    break;
                }else if(s[k]=='L'){
                    if((k-(i+1))%2==0){
                        ans[i+1]++;
                    }else{
                        ans[i]++;
                    }
                }   
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}