#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

int hash[244140625];

int get_char(char ch){
  switch(ch){
    case 'A' :
    return 1;
    case 'C' : 
    return 2;
    case 'G' : 
    return 3;
    case 'T' : 
    return 4;
  };
}

int getkey(string str){
  int sum = 0;
  int p = 1;
  for(int i=0;i<str.size();i++){
    sum += p*get_char(str[i]);
    p *= 5;
  }
  return sum;
}

int main(void){
  int n;
  cin >> n;
  vector<int> out;
  for(int i=0;i<n;i++){
    string str, word; 
    cin >> str >> word;

    int key = getkey(word);
    if(str == "insert"){
      hash[key] = 1;
    }else{
      if(hash[key]){
        out.push_back(1);
      }else {
        out.push_back(0);
      }
    }
  }

  for(int i=0;i<out.size();i++){
    if(out[i]){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
  return 0;
}