#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	string s;
	cin >> s;

	
	for(int i=0;i<s.length();i++){
		if(i%2==0&&s[i]!='h'){
			cout << "No" << endl;
			return 0;
		}
		if(i%2==1&&s[i]!='i'){
			cout << "No" << endl;
			return 0;
		}
		if(s.length()%2!=0){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}
