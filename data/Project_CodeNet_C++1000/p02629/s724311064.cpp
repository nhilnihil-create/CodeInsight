#include <bits/stdc++.h>
using namespace std;

int main() {
   long long n ;
   cin>>n;
   long long x;
   string S[] ={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
   vector<string>v;
   while(n != 0){
        x = (n % 26) -1;
        if(x == -1){
            x = 25;
            n--;
        }
       v.push_back( S[x]);
       n /= 26;
   }
 for(reverse_iterator<vector<basic_string<char>>::iterator> it = v.rbegin(); it != v.rend(); it++){
     cout<<*it;
 }
 cout<<endl;

return 0;

}