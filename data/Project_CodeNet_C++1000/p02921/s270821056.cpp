#include <bits/stdc++.h>
using namespace std;
 
int main(){
   string a,b;
   cin >>a>>b;
   int count = 0;
    if(a.at(0) == b.at(0)){
        count++;
    }if(a.at(1) == b.at(1)){
        count++;
    }if(a.at(2) == b.at(2)){
        count++;
    }cout << count <<endl;
}