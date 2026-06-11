#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	vector<int> sumi(s.size(),0);
	
	reverse(s.begin(),s.end());
	
	int tmp = 10;
	sumi[0] = s[0] -'0';
	vector<int> cnts(2019,0);
	cnts[sumi[0]]++;
	cnts[0] ++;
	int res = 0;
	for(int i=1;i<s.size();++i){
		//cout << i <<endl;
		int a = (s[i] - '0') * tmp;
		//cout << " " << sumi[i-1] << " + " << a << " " << a * tmp <<endl;
		sumi[i] = (sumi[i-1] + a)%2019;
		//cout << sumi[i] << endl;
		res += cnts[sumi[i]];
		cnts[sumi[i]]++;
		tmp = tmp * 10 % 2019; 
	}
	
	cout << res  << endl;

	return 0;
}
