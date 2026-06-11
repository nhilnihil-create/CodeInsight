#include<iostream>
using namespace std;
int main()
{
   long long a, b, c, d;
   cin >> a >> b >> c >> d;
   
   long long ans1, ans2, ans3, ans4;
   ans1 = a*c;
   ans2 = a*d;
   ans3 = b*c;
   ans4 = b*d;
   
   cout << max({ ans1, ans2, ans3, ans4 }) << endl;
   
   return 0;
}