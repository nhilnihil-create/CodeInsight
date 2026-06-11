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
    double p[n];
    for(int i=0;i<n;i++) cin >> p[i];

    double e[n];
    for(int i=0;i<n;i++) {
        e[i]=(p[i]+1)/2;
        //cout << e[i] << endl;
    }
    //cout << endl;

    vector<double> m;
    double tmp=0;
    for(int i=0;i<k;i++) tmp += e[i];
    m.push_back(tmp);
    if(n==k){
        cout << fixed << setprecision(8) << tmp << endl;
        return 0;
    }

    for(int i=k;i<n;i++) {
        tmp = tmp + e[i] - e[i-k];
        m.push_back(tmp);
        //cout << tmp << endl;
    }

    double ma=0;
    for(int i=0;i<m.size();i++) ma=max(ma,m.at(i));
    cout << fixed << setprecision(8) << ma << endl;   
}