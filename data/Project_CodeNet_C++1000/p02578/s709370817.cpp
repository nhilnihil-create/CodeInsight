#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i< int (n); i++)
using namespace std;
typedef long long ll;

int main(){

int n;
cin >> n;
ll ans=0;
vector<int> a(200100);
rep(i,n) cin >> a[i];
rep(i,n-1) if(a[i]>a[i+1]) {
    ans += a[i] - a[i+1];
    a[i+1] = a[i];
}
cout << ans << endl;

}