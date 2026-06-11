#include<bits/stdc++.h>

using namespace std;
int main(){
    long a,sum=0;
    for(int i=0; i<3; i++){
       cin >> a;
       sum+=a;
    }
       if(sum>=22) cout << "bust" << endl;
       else cout << "win" << endl;
    return 0;
}