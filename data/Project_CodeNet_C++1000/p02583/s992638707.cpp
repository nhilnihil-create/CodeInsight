#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
ll l[200];
int solve(){
    int n=0,m=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>l[i];
    }
    //if (n<3) return cout<<m<<endl,0;
    for(int i=0;i<n;i++){
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (l[i]!=l[j]&&l[j]!=l[k]&&l[i]!=l[k]){
                  if ((l[i]+l[j]>l[k])&&(l[i]+l[k]>l[j])&&(l[k]+l[j]>l[i]))
                      m++;
                }
            }
        }
    }
    cout<<m<<endl;
    return 0;
}
int main(){
    int _=1;
//    cin>>_;
    while(_--){
        solve();
    }
}
