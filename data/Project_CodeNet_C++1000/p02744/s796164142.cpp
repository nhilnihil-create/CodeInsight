#define _GLIBCXX_DEBUG
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <random>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

#define REP(i,x) for(int i=0; i<(x); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    queue<pair<string, char>> p;
    p.push(make_pair("a",'a'));
    
    while(p.size()>0){
        string s;
        char a;
        tie(s, a) = p.front();
        p.pop();
        if(s.size() == n){
            cout << s << endl;
            continue;
        }
        for(char i = 'a'; i<=a+1; i++){
            if(i<=a){
                p.push(make_pair(s+i, a));
            } else {
                p.push(make_pair(s+i, a+1));
            }
        }
    }
    
    return 0;
}
