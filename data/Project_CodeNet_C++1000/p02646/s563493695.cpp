#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<int>;
using vec2 = vector<vector<int>>;
 
int main(){
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if(a < b){
        if(a + v * t < b + w * t){
        cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
    	}
    }
    else{
        if(a - v * t > b - w * t){
        	cout << "NO" << endl;
	    }
    	else{
    	    cout << "YES" << endl;
    	}
    }
 
}
