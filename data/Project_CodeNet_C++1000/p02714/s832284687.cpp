#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;cin>>n;
    string s;cin>>s;
    int k=s.size();
    long long ans=0;
    vector<int> r(k+2),g(k+2),b(k+2);
    s='!'+s;
    for(int i=1;i<=k;i++){
        if(s[i]=='R') r[i]++;
        if(s[i]=='G') g[i]++;
        if(s[i]=='B') b[i]++;
    }
    for(int i=k;i>0;i--){
        r[i-1]+=r[i];
        g[i-1]+=g[i];
        b[i-1]+=b[i];
    }
    for(int a=1;a<=k;a++){
        for(int c=a+1;c<=k;c++){
            if(s[a]!=s[c]){
                int o,p,q;o=p=q=1;
                if(s[a]=='R') o=0;
                if(s[a]=='G') p=0;
                if(s[a]=='B') q=0;
                if(s[c]=='R') o=0;
                if(s[c]=='G') p=0;
                if(s[c]=='B') q=0;
                if(o){
                    ans+=r[c];
                    if(c+c-a>k) continue;
                    if(s[c+c-a]=='R'){
                        ans--;
                    }
                }
                else if(p){
                    ans+=g[c];
                    if(c+c-a>k) continue;
                    if(s[c+c-a]=='G'){
                        ans--;
                    }
                }
                else if(q){
                    ans+=b[c];
                    if(c+c-a>k) continue;
                    if(s[c+c-a]=='B'){
                        ans--;
                    }
                }                            
            }
            //cout<<ans<<endl;
        }
    }

    cout<<ans<<endl;
    return 0;
}
