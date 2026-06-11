#include <iostream>
using namespace std;

int main() {
 int a,b;
 cin >>a>>b;
if (a<b){
 string s="a < b";
 cout<<s<<endl;
}else{
 if(a==b){
  string s="a == b";
  cout<<s<<endl;
 }else{
 	string s="a > b";
 	cout<<s<<endl;
 }
}

}