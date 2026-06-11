#include <bits/stdc++.h>
 using namespace std;
int main(){
long long X;
cin >> X;
long long Point = 100, s = 0;
while(Point < X){
 Point += Point / 100;
s++;
 }
cout << s << endl;
return 0;
}
