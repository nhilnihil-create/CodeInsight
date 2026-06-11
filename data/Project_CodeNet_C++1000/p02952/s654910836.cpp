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

bool keta(int x){
    int k = 0, num = x; 
    while(num > 0){
        num /= 10;
        k++;
    }
    if(k % 2 == 1) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(keta(i)) ans++;
    }
    cout << ans << endl;
    
}