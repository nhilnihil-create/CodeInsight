#include <bits/stdc++.h>

#define rev(v) reverse(v.begin(), v.end());
#define mx(v) max_element(v.begin(), v.end());
#define mn(v) min_element(v.begin(), v.end()); 
#define fastio() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));

//ffs = lsb, clz = l0's, ctz = r0's, popcount = 1's 
 //++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
using namespace std;
 //++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    fastio();
    int a,x; cin >> a >> x;
    if(a < x){
        cout << '0';
    }else{
        cout << "10\n";
    }
    return 0;
}