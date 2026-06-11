#include <bits/stdc++.h>
using namespace std ;
 
int main(){
    int64_t A,B;cin>>A>>B;
    int64_t C,D;cin>>C>>D;
    
    int64_t count1 = B/C + B/D - B/lcm(C,D);
    int64_t count2 = (A-1)/C + (A-1)/D - (A-1)/lcm(C,D);
 
    cout << B-count1-A+1+count2 << endl;
    
}