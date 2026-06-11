#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int len = str.length();
	int mid = len/2;
	int r,l;
	if(len%2 != 0){
			r = mid+1;l=mid-1;
		}
	else {
			 l = mid-1;r=mid;
		}
	int count(0);	
	while(r != len || l != -1){
			if(str[l]!=str[r])count++;
			l--;r++;
		}	
	cout<<count;	
	return 0;
	}
