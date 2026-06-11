#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
 
using namespace std;
 
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>
 
typedef vector<int> vec;
typedef vector<vec> mat;
 
const ll mod = 1000000007;
 
int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int n = 1;
    while(n < b){
        n += a - 1;
        ans++;
    }
    cout << ans << endl;
}