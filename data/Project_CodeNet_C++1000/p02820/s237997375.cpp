#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
  int N,K,pointtotal = 0;
  cin >> N >> K;
  vector<int> point(3);
  cin >> point.at(0) >> point.at(1) >> point.at(2);
  string s;
   cin >> s;
  vector<char> command;
  froop1(0,N){
    if(i < K){
	if(s[i] == 'r'){
    	command.push_back('p');
      pointtotal += point.at(2);
    }else if(s[i] == 's'){
      command.push_back('r');
      pointtotal += point.at(0);
    }else{
      command.push_back('s');
      pointtotal += point.at(1);
    }
    }else{
    if(s[i] == 'r'){
      if(command.at(i - K) == 'p'){
        command.push_back(' ');
        continue;
      }
    	command.push_back('p');
      pointtotal += point.at(2);
    }else if(s[i] == 's'){      
      if(command.at(i - K) == 'r'){
        command.push_back(' ');
        continue;
      }
      command.push_back('r');
      pointtotal += point.at(0);
    }else{
        if(command.at(i - K) == 's'){
        command.push_back(' ');
        continue;
      }
      command.push_back('s');
      pointtotal += point.at(1);
    }
    }
  }
  cout << pointtotal << endl;
    
}