#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long n,r=0,g=0,b=0;
    string s;
    cin >> n;
    cin >>s;
    for(int i=0;i<n;i++){
        if(s[i]=='R') r++;
        else if(s[i]=='G') g++;
        else b++;
    }
    long long ans=r*g*b;
    for(int i=0;i<n;i++){
        for(int j=1;i+j*2<n;j++){
            if(s[i]!=s[i+j]&&s[i]!=s[i+j*2]&&s[i+j]!=s[i+j*2]){
                ans--;
            }
        }
    }
    cout << ans;
}
