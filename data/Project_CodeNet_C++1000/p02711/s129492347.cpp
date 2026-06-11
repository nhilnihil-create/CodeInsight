#include <vector>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int main(){
  string s;
cin >> s;
bool flag=false;
for(int i=0;i<3;i++){
  if(s[i]=='7')flag=true;
}
  if(flag){
cout << "Yes" << endl;
}else{
    cout << "No" << endl;
  }

}