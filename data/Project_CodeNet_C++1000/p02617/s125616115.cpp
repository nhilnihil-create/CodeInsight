#include <iostream>
using namespace std;
#define ll long long

ll n;
int main(){
    cin >> n;
    ll ans = n*(n+1)*(n+2);
    ans/=6;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a>> b;
        ll sub =0;
        if(a>b){
            sub = (n+1-a)*(b);
        }
        else{
            sub = (n+1-b)*(a);
        }
        ans-=sub;
    }


    cout << ans << endl;
}
