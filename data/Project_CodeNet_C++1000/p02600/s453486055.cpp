#include<bits/stdc++.h>

using namespace std;
int main(){
    int m;
    cin >> m;
    int ans = 8;
  m-=400;
    for(;;)
    {
        if(m<200)
        {
            break;
        }
      m-=200;
        ans--;
    }
    cout << ans << endl;
}