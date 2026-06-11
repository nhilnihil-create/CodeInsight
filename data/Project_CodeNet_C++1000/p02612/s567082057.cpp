#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin>>n;
    if(n%1000 == 0) cout << 0 << endl;
    else            cout << 1000-n%1000 << endl;
}
