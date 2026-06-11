#include <bits/stdc++.h>
using namespace std;
int main() {
 string R;
 int S,count=0;
 cin >> R ;
for(int i=0;i<(R.size()/2);i++){
   S=R.size()-i-1;
   if(R.at(i)!=R.at(S))
      ++count;
}
 cout << count << endl;
}