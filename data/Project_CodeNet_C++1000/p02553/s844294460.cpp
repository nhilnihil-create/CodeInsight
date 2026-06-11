#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max(a*1LL*c,max(a*1LL*d,max(b*1LL*c,b*1LL*d))); 
}
