#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
string s;
int ans;
int main(void){
    cin>>n>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
            ans++;
        }
    }
    cout<<ans<<endl;

}
