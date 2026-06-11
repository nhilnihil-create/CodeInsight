#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   string s;
   cin >> s;
   if(s.size() % 2 == 0){
         for(int i = 0;i < s.size();i+= 2){
               if(s.substr(i,2) != "hi"){
                     cout << "No" << endl;
                     return 0;
               }
         }
         cout << "Yes" << endl;
   }else{
         cout << "No" << endl;
   }
}
