#include <bits/stdc++.h>
using namespace std;
int int_abc(long long n) {
    string str="abcdefghijklmnopqrstuvwxyz";
    
        return str[n%26];
    
}

int main() {
   long long N;
   cin >> N;
   vector<char> data;
   bool limit =false;
   while(limit==false) {
       data.push_back(int_abc(N-1));
       N--;
       N/=26;
       
       if (N==0) {
           limit = true;
       }
   }
   int len=data.size();
   for (int i=0;i<len;i++) {
       cout << data[len-1-i];
   }
   
   cout << endl;
   
}