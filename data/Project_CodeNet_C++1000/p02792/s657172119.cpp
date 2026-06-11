#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
P f(int x){
    int fst;
    string s=to_string(x);
    fst=s[0]-'0';
    int last=x%10;
    return P(fst,last);
}
int main() {
    int n;cin>>n;
    int si=to_string(n).size();
    if(si==1){
        cout<<n<<endl;
    }else{
        map<P,int> num;
        for(int i=1;i<=n;i++){
            P p=f(i);
            num[p]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            P p=f(i);
            P q(p.second,p.first);
            ans+=num[q];

        }
        cout<<ans<<endl;
    }
}