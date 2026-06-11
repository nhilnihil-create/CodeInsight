#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   int h,w,x;
   cin >> h;
   cin >> w;
   cin >> x;
   int ans = (x + max(h,w) - 1) / max(h,w);
   cout << ans << endl;
}
