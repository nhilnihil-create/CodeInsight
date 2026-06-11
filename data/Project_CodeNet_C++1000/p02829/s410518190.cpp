#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long A, B;

int main(){
	cin >> A >> B;
	set<long long> ans;
	ans.insert(1);
	ans.insert(2);
	ans.insert(3);
	ans.erase(A);
	ans.erase(B);
	cout << *ans.begin() << endl;

}
