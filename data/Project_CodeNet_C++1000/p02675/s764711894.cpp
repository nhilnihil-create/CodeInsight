#include <bits/stdc++.h>
using namespace std;
 
int main(){
	string n;
  	cin >> n;
  	int a = n.size() - 1;
  	if((n.at(a)=='0')||(n.at(a)=='1')||(n.at(a)=='6')||(n.at(a)=='8')) cout << "pon" << endl;
  	else if(n.at(a) == '3') cout << "bon" << endl;
  	else if((n.at(a)=='2')||(n.at(a)=='4')||(n.at(a)=='5')||(n.at(a)=='7')||(n.at(a)=='9'))cout << "hon" << endl;
}