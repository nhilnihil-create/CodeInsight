#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;


int main(){
    int n;
    string s;
    cin >> n >> s;

    int i = 0, j = n-1;
    int cnt = 0;
    while(i<j){
        if(s[i] == 'W' && s[j] == 'R'){
            s[i] = 'R'; s[j] = 'W';
            i++; j--;
            cnt++;
        }else if(s[i] == 'W' && s[j] == 'W') j--;
        else if(s[i] == 'R' && s[j] == 'R') i++;
        else {
            i++; j--;
        }
    }

    cout << cnt << endl;
}