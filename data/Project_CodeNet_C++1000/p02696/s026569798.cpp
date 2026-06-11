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


int main() {
    long long a,b,c;
    cin>>a>>b>>c;
    long long ans=a*min(b-1,c)/b;
    cout<<ans;
    return 0;
}
