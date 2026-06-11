#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	//ifstream cin (".in");
	//ofstream cout (".out");
    int n;
    cin >> n;
    bool ans = false;
    for(int i=1; i<10; i++){
    	for(int j=1; j<10; j++){
    		if(i*j == n){
    			ans = true;
    		}
    	}
    }
    if(ans == true){
    	cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }
    return 0;

}