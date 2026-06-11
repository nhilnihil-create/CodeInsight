#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
long long x,y,n,i,r;
map<long long,long long> mp;
int main() {
    cin >> x >> n;
    for(i = 0; i < n; i++) {
        cin >> y;
        mp[y] = 1;
    }
    i = x;
    while(mp[i]) {
        i++;
    }
    r = i-x;
    i = x;
    while(mp[i]) {
        i--;
    }
    if(r < x-i) {
        cout << x+r;
    } else {
        cout << i;
    }   
    return 0;
}