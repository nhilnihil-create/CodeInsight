#include <iostream>

using namespace std;

int main(){
int n,temp,ret;
cin >> n;
temp = n / 1000;
ret = n % 1000;
if(ret != 0) cout << (temp+1)*1000-n << endl;
else cout << 0 << endl;
return 0;
}
