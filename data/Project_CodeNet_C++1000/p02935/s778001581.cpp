#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i,N) cin >> v[i];
    sort(v.rbegin(), v.rend());
    double a=v.back();
    v.pop_back();
    rep(i,N-1){
        double b=v.back();
        v.pop_back();
        a = (a+b)/2;
    }
    cout << a << endl;
    return 0;
    
    
}
