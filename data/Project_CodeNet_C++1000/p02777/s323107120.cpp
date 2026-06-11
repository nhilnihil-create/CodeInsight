#include <bits/stdc++.h>
using namespace std;
#define l long

int main(){
     ios::sync_with_stdio(0);
     cin.tie(0);
     
     string a,b,c;
     int x,y;
     
     cin >> a >> b;
     cin >> x >> y;
     cin >> c;
     
     
     if(c == a){x-=1;}
     if(c == b){y-=1;}
     
     cout << x <<" "<< y;
     
     
     
     
}
