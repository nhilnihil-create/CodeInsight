#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define max 100005
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

/*
bool isDiff(int i,int j,int k){
    if((s[i]!=s[j])&&(s[j]!=s[k])&&(s[k]!=s[i])){
        return true; 
    }else{
        return false;
    }
}
*/

int main(){
    int n;
    string s;
    cin>>n>>s;

    ll r=0,g=0,b=0;
    rep(i,n){
        if(s[i]=='R'){
            r++;
        }else if(s[i]=='G'){
            g++;
        }else{
            b++;
        }
    }
    ll comb=r*g*b;

    for(int j=1;j<n;j++){
        rep(i,j){
            int  k=2*j-i;
            if(k<n){
                if(s[i]==s[j] || s[i]==s[k] || s[j]==s[k])continue;
                comb--;
            }
        }
    }
    cout<<comb<<endl;
    return 0;
}
