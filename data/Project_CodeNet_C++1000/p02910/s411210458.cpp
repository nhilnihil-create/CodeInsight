#include<bits/stdc++.h>
using namespace std;
int main(void){
char str[100 + 1];
cin>>str;
int n = strlen(str); 
for (int i = 0; i < n; i++) {
 if (i % 2 == 0) {
if (str[i] == 'L') {
 cout<<"No";
 return 0;
}
} 
  else {
if (str[i] == 'R') {
 cout<<"No";
return 0;
}
 }
 }

cout<<"Yes";
   return 0;
 }
