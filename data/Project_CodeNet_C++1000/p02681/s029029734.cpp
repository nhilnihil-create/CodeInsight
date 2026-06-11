#include <bits/stdc++.h>
using namespace std;

int main(){
string S, T, U;
cin >> S >> T;
for(int i=0;i<T.size()-1;i++){
	if(S.at(i) != T.at(i)){
		cout << "No" << endl;
		return 0;
	}
}
cout << "Yes" << endl;

}