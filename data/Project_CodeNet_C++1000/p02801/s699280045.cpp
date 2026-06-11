#include <bits/stdc++.h>
using namespace std;

int main(){
	char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char k;
	cin>>k;
	int c = -1;
	for (int i = 0; i<26; i++){
		c++;
		if (arr[i] == k){
			break;
		}
	}
	cout<<arr[c+1];
}