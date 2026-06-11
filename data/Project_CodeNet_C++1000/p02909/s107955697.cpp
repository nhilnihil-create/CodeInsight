#include<bits/stdc++.h>
using namespace std;

#define ASC(vec) vec.begin(), vec.end() 
#define DESC(vec) vec.rbegin(), vec.rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define In(vec) rep(i, n) cin>>vec[i]; 
#define ANS(s) cout << s << endl;
#define inc(a, b) cin >> a >> b;

int main(){
	map<string,string> tamesi;
	vector<string> tamesi2 = {"Sunny","Cloudy","Rainy"};
	tamesi[tamesi2[0]] = tamesi2[1];
	tamesi[tamesi2[1]] = tamesi2[2];
	tamesi[tamesi2[2]] = tamesi2[0];

	string a;

	cin>>a;
	cout<<tamesi[a];
	return 0;
}
