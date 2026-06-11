#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,sub;
    float ans;
    cin >> n;
       if(n%2==0){
          sub = (n/2);
          ans = (1.0)*sub/n;
       }
       else{
          sub = (n+1)/2;
          ans = (1.0)*sub/n;
    
       }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}