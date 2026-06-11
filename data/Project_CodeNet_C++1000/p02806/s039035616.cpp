#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s[n],x;
    int t[n];
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i];
        if(i)t[i]+=t[i-1];
    }
    cin>>x;
    for(int i=0;i<n;i++){
        if(s[i]==x){
            cout << t[n-1]-t[i] <<endl;
            return 0;
        }
    }

    return 0;
}
