#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll N;
    cin>>N;

    int n;
    vector<char> s;
    if(N<27){
        n=N%27;
        cout<<char('a'+n-1);  
        return 0;
    }else{
        while(N>0){
            int n=N%26;
            if(n==0) n=26;
            s.push_back(char('a'+n-1));
            N=(N-1)/26;
            if(N==0) break;
        }
    }

    rep(i, s.size()) cout<<s[s.size()-i-1];

    return 0;
}