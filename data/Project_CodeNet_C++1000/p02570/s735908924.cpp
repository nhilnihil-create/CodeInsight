#include <bits/stdc++.h>
using namespace std;

#define print cout << 

int main(){
    int dist,time , speed;
    cin >> dist >> time >> speed;

    if((double)dist/speed<=time){
      print "Yes" << endl;
    }else{
      print "No" << endl;      
    }

}
