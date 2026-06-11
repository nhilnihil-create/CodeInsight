#include<iostream>
#include<string>

using namespace std;

int main() {
  	int k;
  cin>>k;
  	string str = "";
  	while(k) {
    	str += "ACL";
      	k--;
    }
  
  	cout<<str<<'\n';
	return 0;
}