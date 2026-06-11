#include<bits/stdc++.h>

using namespace std;
int main(){
    string n;
    cin >> n;
    bool test=true;
    for(int i=0; i<3; i++){
       if(n[i]=='7')
            test = false;
   }
    if(test) cout << "No" << endl;
            else cout << "Yes" << endl;
   return 0;
}