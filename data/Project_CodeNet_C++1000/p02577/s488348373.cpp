#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 string n;
 cin >> n;
 int sum = 0;
 for(int i=0;i<n.size();i++){
       sum +=n[i]-'0';
 }
 if(sum%9==0){
 cout << "Yes" << endl;
 }else{
       cout << "No" << endl;
 }
 return 0;
}