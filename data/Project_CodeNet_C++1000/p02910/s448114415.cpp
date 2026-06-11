#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	for (int i=0; i<S.size(); i++){
	    if (i%2==0){
	        if (S.at(i)!='R' && S.at(i)!='U' && S.at(i)!='D'){
	            cout << "No" << endl;
	            return 0;
	        }
	    }
	    if (i%2==1){
	        if (S.at(i)!='L' && S.at(i)!='U' && S.at(i)!='D'){
	            cout << "No" << endl;
	            return 0;
	        }
	    }
	}
	cout << "Yes" << endl;
}