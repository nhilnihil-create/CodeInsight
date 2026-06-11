#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main(){
    ll a, b, c; cin >> a >> b >> c;
    if(4*a*b < (c-a-b)*(c-a-b) && c > (a+b)) cout << "Yes";
    else    cout << "No";
}