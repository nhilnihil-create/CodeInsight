#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int x;
	cin >> x;
	while(x > 3100) x-= 1000;
	bool isOK = false;
	rep(a, 21){
		rep(b, 21){
			rep(c, 21){
				rep(d, 21){
					rep(e, 21){
						rep(f, 21){
							if(100*a + 101*b + 102*c + 103*d + 104*e + 105*f == x) isOK = true;
						}
					}
				}
			}
		}
	} 

	if(isOK) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}