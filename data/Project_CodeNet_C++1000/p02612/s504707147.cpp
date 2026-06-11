#include<bits/stdc++.h>

using namespace std;
int main(){
    long n;
    cin >> n;
    if(n%1000==0) cout << "0" << endl;
    else{
      n=n%1000;
      n=1000-n;
      cout << n << endl;
    }
    return 0;
}