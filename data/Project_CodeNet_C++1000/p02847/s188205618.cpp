#include<bits/stdc++.h>
using namespace std;

int main(){
string S;
cin >> S ;
 
vector<string>data={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  int answer;
for(int i=0;i<data.size();i++){
    if(S==data.at(i)){
     answer=7-i;
    }
}

  cout << answer << endl;
}
