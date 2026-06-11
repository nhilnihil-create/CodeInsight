#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;
const ll mod=1000000007,mod9=1000000009;
template <class T>inline T lcm(T a,T b){return (a*b/__gcd(a,b));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n>3){
        if(a[n-1]==0){
            cout <<"Yes"<<endl;
        }
        else if(n%3){
            cout << "No"<<endl;
        }
        else{
            if(a[0]==a[n/3-1]&&a[n/3]==a[2*n/3-1]&&a[2*n/3]==a[n-1]&&(a[0]^a[n/3]^a[n-1])==0){
                cout << "Yes"<<endl;
            }
            else{
                cout <<"No"<<endl;
            }
        }
    }
    else{
        if(a[0]^a[1]^a[2]){
            cout << "No"<<endl;
        }
        else{
            cout <<"Yes"<<endl;
        }
    }
    return 0;
}

