#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
void Main(){
    int n;cin>>n;
    vector<double> a(n);
    For(i,0,n) cin>>a[i];
    sort(ALL(a));
    For(i,0,n-1) a[i+1]=(a[i]+a[i+1])/2;
    cout<<fixed<<setprecision(8)<<a[n-1]<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}