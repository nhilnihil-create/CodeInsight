#include <bits/stdc++.h>
using namespace std;
int main(void){
   
   string s;
   cin >> s;
   int len = s.size();
   int c = 0;
   for(int i=0;i<len;i++){
       if(i%2 == 0){
           if(s[i] == 'R' || s[i] == 'U' || s[i] == 'D') c++;
       }
       else{
           if(s[i] == 'L' || s[i] == 'U' || s[i] == 'D') c++;
       }
   }
   
   if(c == len){
       cout << "Yes" <<endl;
   }
   else{
       cout << "No" <<endl;
   }
}