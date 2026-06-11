 #include <bits/stdc++.h>
 using namespace std;
 
 int n,m,T;
 int x;
 
 int main()
 {
 	cin >> n >> x >> T;
 	int now = n%x == 0 ? n/x : n/x+1;
 	cout << now * T << endl;
	 return 0;
 }