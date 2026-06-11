 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;
 
 int main(){
	 int a,b;
	 cin >> a >> b;
	 if((a+b)%2) cout << "IMPOSSIBLE" << endl;
	 else cout << (a+b)/2 << endl;
   return 0;
 }