#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    if(n%2==1){
        cout<<0<<endl;
    }else{
        ll divide = 10;
        while(n>=divide){
            ans += n/divide;
            divide *= 5;
        }
        cout<<ans<<endl;

    }
    

    return 0;
}
