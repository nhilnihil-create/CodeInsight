#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#include <map>
#define rep(i,n) for (int i=0;i<(n);++i)
#define REP(i,n) for (int i=0;i<=(n);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int INF = 10000000;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
    int n;
    cin >> n;
    set<string> words;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        words.insert(s);
    }
    cout << words.size() << endl;
    return 0;
}
