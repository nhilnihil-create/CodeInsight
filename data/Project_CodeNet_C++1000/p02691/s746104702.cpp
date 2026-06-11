#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1234567;

int main() {
    int n;
    cin>>n;
    map<int,int>mp;
    long long ans=0;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        ans+=mp[i-x];
        mp[x+i]++;
    }
    cout<<ans;
    return 0;
}
