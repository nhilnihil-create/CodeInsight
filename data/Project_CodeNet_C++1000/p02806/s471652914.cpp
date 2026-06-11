#include<bits/stdc++.h>
using namespace std;

const int maxn=57;
int n,t[maxn];
string s[maxn],st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s[i]>>t[i];
    }
    cin>>st;
    for (int i=1;i<=n;++i){
        if (s[i]==st){
            int ret=0;
            for (int j=i+1;j<=n;++j) ret+=t[j];
            cout<<ret<<endl;
            return 0;
        }
    }
    return 0;
}