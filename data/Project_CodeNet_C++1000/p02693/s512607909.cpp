#include <bits/stdc++.h>

using namespace std;

int main ()
{int K,A,B;
 int iBuf;
  cin >> K;
  cin >> A >> B;
 for(int i = A; i <= B; i++)
 {
   iBuf = i % K;
   if(iBuf == 0)
   {
     cout << "OK" << endl;
     break;
   }
 }
 if(iBuf != 0)
 {
   cout << "NG" << endl;
 }
return 0;
}

