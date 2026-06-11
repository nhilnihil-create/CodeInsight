#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int a[n];
    int l=1,hl=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        l=lcm(l,a[i]);
        hl=lcm(hl,a[i]/2);
    }
    for(int i=0;i<n;i++){
        if((hl-a[i]/2)%a[i]!=0){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<max(0,m/hl-m/l)<<endl;
}