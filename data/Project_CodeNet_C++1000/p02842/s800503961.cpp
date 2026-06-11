#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    int N,x(0);
    cin >> N ;
    int i(0),ans(0);
    while(x<N){
       x = i*1.08;
       if(N==x){
           ans = i;
           break;
        }
       i++;
    }
    if(ans == 0){
        cout << ":(" << endl;
    }
    else{
        cout << ans << endl;
    }


}