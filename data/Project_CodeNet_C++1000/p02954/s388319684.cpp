#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

int main(){
	string s; cin >> s;
    ll rs, rf, ls, lf;
    vll a(s.size(),0);
    if(s[0] == 'L'){
    	ll i = 0;
        while(s[i] == 'L'){
        	a[0]++;
            i++;
    	}
        rs = a[0];
     }
     else{rs = 0;}
     
    rep(i, rs+1, s.size()){
 		if(s[i] == 'R' && s[i-1] == 'L'){
        	lf = i-1;
            ll total = lf - rs + 1;
            if(total % 2 == 0){a[rf] = total/2; a[ls] = total/2;}
            else{
            	a[rf] = total/2 + (rf - rs + 1) % 2;
                a[ls] = total/2 + (ls - rs + 1) % 2;
            }
            rs = i;            
        }
        else if(s[i] == 'L' && s[i-1] == 'R'){
        	rf = i-1;
            ls = i;
        }
      if(i == s.size()-1 && s[i] == 'R'){a[i] = i - rs + 1;}
      else if(i == s.size()-1 && s[i] == 'L'){
        lf = i;
            ll total = lf - rs + 1;
            if(total % 2 == 0){a[rf] = total/2; a[ls] = total/2;}
            else{
            	a[rf] = total/2 + (rf - rs + 1) % 2;
                a[ls] = total/2 + (ls - rs + 1) % 2;
            }
      }
    }
    rep(i, 0, a.size()){
    	cout << a[i] << " ";
        }
}

