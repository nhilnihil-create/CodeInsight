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
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> l;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        l.push_back(m);
    }
    sort(l.begin(),l.end());

    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int tmp=l.at(i)+l.at(j);
            for(int k=j+1;k<n;k++){
                if(l[k]>=tmp) break;
                if(l[j]<l[i]+l[k]) ans++;
            }
        }
    }

    cout << ans << endl;
}