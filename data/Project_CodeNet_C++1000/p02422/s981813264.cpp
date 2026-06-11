#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string str;
	cin >> str >> n;
	for(int i=0 ; i<n ; i++ ){
		string sign , st;
		int x,y;
		cin >> sign >> x >> y;
		if( sign=="print" ){
			for( int j=x ; j<=y ; j++ )
				cout << str[j];
			cout << endl;
		}		
		else if( sign =="reverse"){
			string tmp="";
			for( int j=y ; j>=x ; j-- )
				tmp+=str[j];
			for( int j=x ; j<=y ; j++ ){
				str[j] = tmp[j-x];
			//	cout << tmp[j-x] <<" ";
			}
			//cout << endl;
		}
		else if( sign=="replace"){
			cin >> sign;
			for( int j=x ; j<=y ; j++ )
				str[j] = sign[j-x];
		}
		//else
		//	cout << "NO" << endl;
	}
	return 0;
}