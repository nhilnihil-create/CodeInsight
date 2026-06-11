#include<bits/stdc++.h>

using namespace std;
#define max 10005
int main(){
    long n,a,i=0;
    bool test = true;
    cin >> n;
    for(i; i<n; i++){
      cin >> a;
          if(a%2==0 && a%3!=0 && a%5!=0)
             test = false;
    }
    if(test) cout << "APPROVED" << endl;
    else
      cout << "DENIED" << endl;
    return 0;
}