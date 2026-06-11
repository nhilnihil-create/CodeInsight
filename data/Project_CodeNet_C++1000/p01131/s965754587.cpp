#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string s[9]={".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(){
  int n;
  string input;
  
  cin >> n;
  
  for(int i=0; i<n; i++){
    char output[76] = "";
    cin >> input;
    char num = '0';
    int kaisu = 0;
    int outlength = 0;
    
    for(int j=0; j<(int)input.length(); j++){
      if(input[j] != '0'){
	num = input[j];
	kaisu++;
      }else if(input[j] == '0' && kaisu != 0){
	output[outlength] = s[atoi(&num)-1][(kaisu-1)%s[atoi(&num)-1].length()];
	kaisu = 0;
	num = '0';
	outlength++;
      }
    }
    output[outlength] = '\0';
    cout << output << endl;
  }
  return 0;
}