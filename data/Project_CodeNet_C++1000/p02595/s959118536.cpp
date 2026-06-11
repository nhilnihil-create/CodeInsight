#include<bits/stdc++.h>

using namespace std;
int main(){
    long n,d,count=0;
    cin >> n >> d;
    while(n--){
       long a,b;
       cin >> a >> b;
       if(sqrt(a*a+b*b) <= d)
          count++;
    }
    cout << count << endl;
    return 0;
}