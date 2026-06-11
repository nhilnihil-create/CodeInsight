#include <bits/stdc++.h>
using namespace std;

int main(){
int t=0,s=0;;
string S,T;
cin >> S>>T;
for(int i=0; i<S.length()-T.length()+1; i++){
	t=0;
	for(int j=0; j<T.length(); j++){
		if(S.at(i+j)==T.at(j)) t++;
		if(s<t) s=t;
	}
}
cout << T.length()-s << endl;

}