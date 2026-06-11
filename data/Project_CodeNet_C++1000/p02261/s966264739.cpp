#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

lli n;
vst a;
vst b;
vst c;

void output(vst a){
    cout << a[0];
    for(lli i = 1;i < n;i++){
        cout << " " << a[i];
    }
    cout << endl;
}

int main(){
    cin >> n;
    a = vst(n);
    for(lli i = 0;i < n;i++) cin >> a[i];
    b = a;
    for(lli i = n-1;i >= 0;i--){
        for(lli j = n-1;j > 0;j--){
            if(b[j][1] < b[j-1][1]) swap(b[j],b[j-1]);
        }
    }
    output(b);
    cout << "Stable" << endl;
    for(auto itr = a.begin();itr < a.end();itr++){
        auto jtr = min_element(itr,a.end(),[](string a,string b){
            return a[1] < b[1];
        });
        if(itr == jtr) continue;
        swap(*itr,*jtr);
    }
    output(a);
    for(lli i = 0;i < n;i++){
        if(a[i] != b[i]){
            cout << "Not stable" << endl;
            return 0;
        }
    }
    cout << "Stable" << endl;
    return 0;

    

}