#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int gcd(int a, int b) {
    if(a%b==0) {
        return b;
    }
    return gcd(b,a%b);
}

int ans;
int k;
void dfs(vector<int> s) {
    if(s.size()==3) {
        ans+=gcd(gcd(s[0],s[1]),s[2]);
        //cout<<s[0]<<' '<<s[1]<<' '<<s[2]<<endl;
        return;
    }

    for(int i=1;i<=k;i++) {
        s.push_back(i);
        dfs(s);
        s.pop_back();
    }

    return;
        
}

int main() {
    fast_io;
    ans=0;

    cin>>k;

    vector<int> s;

    dfs(s);
    cout<<ans<<endl;


}


