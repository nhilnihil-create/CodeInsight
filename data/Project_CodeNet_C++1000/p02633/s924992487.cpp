            #include <bits/stdc++.h>
            #define ll long long
            #define ld long double
            using namespace std; 
            int gcd(int a, int b){
              	if (a == 0) 
           			return b;  
        		return gcd(b % a, a); 
            }
        	int lcm (int a, int b){
             	return a*b/gcd(a,b);
            }
            int main(){
            	ll x;
              	cin >> x;
              	cout << lcm(x, 360)/x << endl;
            	return 0;
            }