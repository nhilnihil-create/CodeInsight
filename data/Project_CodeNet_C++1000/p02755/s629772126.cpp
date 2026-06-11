#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   
    int A,B,i=1;
    cin >> A >> B;

    while(1){
        if((int)(i * 0.08) == A && (int)(i * 0.1) == B) break;
        if((int)(i * 0.08) > A) {i = -1; break;}
        i++;
    }
    
    cout << i << endl;
}