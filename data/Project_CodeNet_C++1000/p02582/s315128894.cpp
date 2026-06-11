#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int main(){
 string s;
 cin >> s;
 if(s=="SSS"){
    cout << 0 << endl;
 }else if(s == "RRS" || s == "SRR"){
     cout << 2 << endl;
 }else if(s == "RRR"){
     cout << 3 <<endl;
 }else{
     cout << 1 << endl;
 }
 return 0;
}