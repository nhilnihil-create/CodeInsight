#include<bits/stdc++.h>
#define N 400050
#define int long long
#define pb push_back
#define x first
#define y second
#define all(v) v.begin(),v.end()
#define coffee prince
#define sz(a) (int)a.size()
#define ll long long
#define SIZE N
using namespace std;
int pr[N],su[N],n,k,c;
string s;
int fi[N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k>>c>>s;
    int ma = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='x'){
            pr[i] = ma;
        }
       else{
           if(i<=c)pr[i] = 1;
        else pr[i] = 1+pr[i-c-1];
       }
       ma = max(ma,pr[i]);
    }
    ma = 0;
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='x'){
            su[i] = ma;
        }
        else{
            if(i+c+1>=n)su[i] = 1;
            else su[i] = 1+su[i+c+1];
        }
        ma = max(ma,su[i]);
    }
    int rp = 0;
    set< int > o;
  for(int i=0;i<n;i++)
    o.insert(i);
    if(su[1]>=k)o.erase(0);
 	if(n>1&&pr[n-2]>=k)o.erase(n-1);
    for(int i=0;i<n;i++){
   // 	cout<<i<<" "<<rp<<"\n";
      	rp = max(rp,i+1);
      	if(pr[i]+su[i+c+1]>=k){
          while(rp<i+c+1){
            o.erase(rp++);
          }
        }
      else continue;
        while(rp+1<n&&pr[i]+su[rp+1]>=k)o.erase(rp++);
        if(rp>=n-1)break;
    }
    for(auto j: o)
        cout<<j+1<<"\n";
        return 0;
}
