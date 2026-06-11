#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<1000;i++){
        int c[3]={i/100,(i/10)%10,i%10};
        int f=0;
        rep(j,n){
            if(('0'+c[f])==s[j]) f++;
            if(f==3) {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}