/*
      author  : nishi5451
      created : 15.08.2020 12:06:13
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin 
    >> n;
    double ans=0.0;
    rep(i,n){
        int a;
        cin >> a;
        ans += 1.0/a;
    }
    printf("%.12lf\n",1.0/ans);
    return 0;
}