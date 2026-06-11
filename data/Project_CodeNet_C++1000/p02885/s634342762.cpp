#include <iostream>
 using namespace std;
 int main(){
 int A, B, ans;
 cin >> A >> B;
 ans = max(0, A - 2 * B);
 cout << ans << endl;
 return 0;
 }