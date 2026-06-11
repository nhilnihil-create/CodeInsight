#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)

int main(){
	string W,T;
	long long int c=0;
	cin >> W;
	for (int i = 0; i < W.length(); i++){
		if (isupper(W[i])){
			W[i] = tolower(W[i]);
		}
	}
	while (cin>>T){
		if (T == "END_OF_TEXT")break;
		for (int i = 0;i<T.length(); i++){
			if (isupper(T[i])){
				T[i] = tolower(T[i]);
			}
		}
		if (T == W)c++;
	}
	cout << c << '\n';
	return 0;
}