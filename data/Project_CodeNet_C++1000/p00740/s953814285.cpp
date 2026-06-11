#include <iostream> 
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <deque>  
#include <iomanip>

using namespace std;

using ll = long long;
#define INF 1e9
#define MOD 1e9 + 7
#define rep(i, n) for(int i = 0; i < n; i++)
#define loop(i, a, n) for(int i = a; i < n; i++)
#define all(in) in.begin(), in.end()
int main(){
    int n, r;
    while(true){
        cin >> n >> r;
        if(n == 0 && r == 0) break;
        int ans  = 0;
        int box = r;
        map<int, int> mp;
        rep(i, n) mp[i]  = 0;
       bool flag = false; 
        while(true){
           rep(i, n){
               if(box > 0){
                   mp[i]++;
                   box--;
               }else{
                   box = mp[i];
                   mp[i] = 0;
               }
               if(mp[i] == r){
                   ans = i;
                   flag = true;
                   break;
               }
           } 
           if(flag) break;
        }
        cout << ans << endl;
    }
    return 0;
}
