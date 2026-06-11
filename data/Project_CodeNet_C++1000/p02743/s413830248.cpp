#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;

vector<pair<int, int>> to[100010];
bool visited[100010];
ll dist[100010];
int main() {
    
    ll a,b,c;
    cin>>a>>b>>c;
    if((c-a-b) < 0) {
       cout << "No" << endl;
        return 0;
    }
    
    if(4*a*b < (c-a-b)*(c-a-b)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}