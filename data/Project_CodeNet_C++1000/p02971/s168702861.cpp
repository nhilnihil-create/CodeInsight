#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int max1,max2;
    max1 = max(a[0],a[1]);
    max2 = min(a[0],a[1]);
    for(int i=2; i<n; i++){
        if(max1 < a[i]){
            max2 = max1;
            max1 = a[i];
        }
        else if (max1 == a[i]){
            max2 = a[i];
        }
        else if(max1 > a[i] && a[i] > max2){
            max2 = a[i];
        }
    }
    int ans;
    rep(i,n){
        if(a[i] == max1){
            ans = max2;
        }
        else{
            ans = max1;
        }
        cans;
    }
    return 0;
}