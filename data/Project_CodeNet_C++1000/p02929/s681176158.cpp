#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
typedef long long int ll;

ll mod=1e9+7;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i=0;i<2*n;i++){
        if(i%2==0){
            s[i]=(s[i]=='B'?'W':'B');
        }
    }
    ll ans=1;
    ll w=0;
    for(int i=0;i<2*n;i++){
        if(s[i]=='W')w++;
        else if(w==0&&s[i]=='B'){
            cout << 0 << endl;
            return 0;
        }
        else{
            ans*=w;
            ans%=mod;
            w--;
        }
    }
    if(w>0){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        (ans*=i)%=mod;
    }
    cout << ans << endl;
}