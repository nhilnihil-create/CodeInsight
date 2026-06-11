 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;
 
 int main(){
	 string s;
	 cin >> s;
	 int cnt=0;
	 rep(i,s.size()/2){
		 if(s[i]!=s[s.size()-1-i]) cnt++;
	 }
	 cout << cnt << endl;
   return 0;	
 }