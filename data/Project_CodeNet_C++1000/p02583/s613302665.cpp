#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
    int n;
    cin>>n;
    vector<lli> a(n);
    rep(i,n)
    cin>>a[i];
    sort(a.begin(),a.end());
    int cnt =0 ;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int x =a[i],y= a[j] ,z =a[k];
                if( x!=y && y!=z && z!=x &&x+y>z && y+z >x && z+x>y)
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    

}



int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
}