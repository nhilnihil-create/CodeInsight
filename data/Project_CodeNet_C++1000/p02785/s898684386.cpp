#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using intl = int64_t;
using graph = vector<vector<int> >;
int main(){
    int n,k;
    cin >> n >> k;

    vector<intl> h;
    for(int i=0;i<n;i++){
        intl f;
        cin >> f;
        h.push_back(f);
    }

    if(n<=k) {
        cout << 0 << endl;
        return 0;
    }

    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());

    intl sum=0;
    for(int i=k;i<n;i++){
        sum += h.at(i);
    }
        
    cout << sum << endl;
}
