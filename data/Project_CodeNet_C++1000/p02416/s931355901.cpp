#include<iostream>
#include<string>

using namespace std;

int main(){

  string string;
  int sum,i,j=0;
  int sum_list[1000] = {0};

while(1){
  cin >> string;
    if(string == "0"){
      break;
    }
    sum = 0;
    for(i = 0; i < string.size() ;i++){
      sum += string[i] - '0';
    }
      sum_list[j++] = sum;
      string.clear();
  }

  for(i = 0;sum_list[i] != 0;i++){
    cout << sum_list[i] << endl;
  }
  return 0;
}