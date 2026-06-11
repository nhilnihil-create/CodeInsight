#include <iostream>
using namespace std;
int main(void){
int n, s;
cin >> n >> s;
int cnt = 0;
while(n > 0) {
n /= s;
cnt ++;
}

cout << cnt << endl;
}