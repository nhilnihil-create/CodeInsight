#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000000000
#define MOD 1000000007

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    string s;
    cin>>s;
    int ans=0;
    for(int i=0; i<s.length()/2; i++){
        if(s[i]!=s[s.length()-i-1])   ans++;
    }
    cout<<ans<<endl;
    return 0;
}