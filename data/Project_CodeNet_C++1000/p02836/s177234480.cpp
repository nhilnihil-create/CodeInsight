#include<bits/stdc++.h>
using namespace std;
int main(){
   int N;
   int count = 0;
   string s;
   cin >> s;
   N = s.size();
   for(int i = 0;i<N;i++){
     if(s[i] != s[N-1-i]){
          count++;
     }
   }
   cout << count /2 << endl;
}