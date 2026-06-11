#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
using namespace std;

int main(){
   int n; cin >> n;
   string s; cin >> s;
   int now=1;
   int ans=0;
   while(now<n){
        int tmp=0;
        rep(i,n-now){
            if(tmp>=now){
               ans=max(ans,tmp);
               tmp=0;
               continue;
            }
            if(s[i]==s[i+now]) tmp++;
            else{
               ans=max(ans,tmp);
               tmp=0;
            }
        }
        ans=max(ans,tmp);
        now++;
    }
    cout << ans << endl;
return 0;
}
