#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // fixed, setprecision 
#include <math.h> // double sqrt
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
string zisho(string a){
    sort(a.begin(), a.end());
    return a;
}

int main(){
    long long n;
    cin>>n;
    vector<string>s(n);
    rep(i,n)cin>>s[i];
    rep(i,n)s[i]=zisho(s[i]);
    map<string,int>xx;
    long long count=0;
    rep(i,n){
    if(xx.count(s[i])){xx.at(s[i])++;count+=xx.at(s[i])-1;}
    else xx[s[i]]=1;
    }
    cout<<count;
return 0;
}