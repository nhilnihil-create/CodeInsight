#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main(){
    int k,x,min,max; cin >> k >> x;
    max = x+k-1;
    min = x-k+1;
    for(int i=min; min<=max; ++min){
        cout << min << endl;
    }
}