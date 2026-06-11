// atcoder 175

//A
#include <iostream>
using namespace std;
#define ll  long long
#define M 1000000007
#define tc int t; cin>>t; while(t--)
#include <cstring>
int main(){
	string s;
	cin>>s;
	int l = 0, maxL = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R' && maxL <= l){
			l++;
			maxL = l; 
		}
		else if(s[i] == 'S'){
			l = 0; 
		}
	}
	cout << maxL << endl;
	return 0;
}