#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    int cnt=0;
    For(i,0,n-1)if(s[i]!=s[i+1]) cnt++;
    ans=n-1-max(cnt-2*k,0);
    cout<<ans<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}