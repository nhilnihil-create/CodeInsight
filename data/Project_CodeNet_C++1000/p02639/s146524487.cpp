#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int m[5] = {0};
    int ans;
    for(int i=1; i<=5; i++){
        cin >> m[i];
    }
    for(int i=1; i<=5; i++){
        if(m[i]==0){
            ans = i;
        }
    }
    cout << ans << endl;
   
}
 