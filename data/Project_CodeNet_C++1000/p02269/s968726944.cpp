#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_set>
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

unordered_set<string> s;

lli n;

int main(){
    string st;
    string con;
    cin >> n;
    for(lli i = 0;i < n;i++){
        cin >> st >> con;
        if(st == "insert") s.insert(con);
        if(st == "find") cout << (s.count(con) ? "yes" : "no") << endl;
    }
    return 0;
}