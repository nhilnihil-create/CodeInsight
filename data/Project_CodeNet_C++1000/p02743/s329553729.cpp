#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
  
int main(void){
    ll a, b, c;
    
    cin >> a >> b >> c;
    //cout << sqrt(a) << " " << sqrt(b) << " " << sqrt(c) << endl;
    if (((c-a-b)>0) && ((4*a*b) < (c-a-b)*(c-a-b))) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}