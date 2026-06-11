#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int gcd(int a, int b) {
    while(b != 0) {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;

}

int ans;
int k;
//void dfs(vector<int> s) {
//    if(s.size()==3) {
//        ans+=gcd(gcd(s[0],s[1]),s[2]);
//        //cout<<s[0]<<' '<<s[1]<<' '<<s[2]<<endl;
//        return;
//    }
//
//    for(int i=1;i<=k;i++) {
//        s.push_back(i);
//        dfs(s);
//        s.pop_back();
//    }
//
//    return;
//        
//}

int main() {
    fast_io;
    ans=0;

    cin>>k;

    for(int i=1;i<=k;i++) {
        for(int j=1;j<=k;j++) {
            for(int l=1;l<=k;l++) {
                ans+=gcd(gcd(i,j),l);
            }
        }
    }

    cout<<ans<<endl;


}


