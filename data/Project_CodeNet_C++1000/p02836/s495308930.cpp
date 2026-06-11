#include <bits/stdc++.h>
using namespace std;

int main(){
  	int i,count=0;
 	string s;
  	cin >> s;
  	for(i=0;i<s.size()/2;i++){
     if(s[i] != s[s.size()-(i+1)]) count++; 
    }
   cout << count << endl;
  
}