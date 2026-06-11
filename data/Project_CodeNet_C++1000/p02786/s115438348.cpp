#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll kill_monster(ll health){
    if(health == 1)
        return 1;
    return 1 + 2 * kill_monster(health / 2);
}
int main() {
    
   ll H;
   cin >> H;
   cout << kill_monster(H);

   return 0;
}
