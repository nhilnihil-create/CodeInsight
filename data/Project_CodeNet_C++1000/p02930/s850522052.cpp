#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=(i^j);
            int ans=1;
            while(t%2==0){
                t>>=1;
                ans++;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}