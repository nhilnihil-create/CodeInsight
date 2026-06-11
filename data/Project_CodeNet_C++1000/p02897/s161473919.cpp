/*
      author : nishi5451
      created: 11.08.2020 22:23:06
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    double ans = (n+n%2)/2/double(n);
    printf("%.12lf\n",ans);
    return 0;
}