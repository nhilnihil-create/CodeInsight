#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <bitset>
using namespace std;
int main(){
    int h, n;
    cin >> h >> n;
    int a[100100];
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    if(h > total) cout << "No" << endl;
    else cout << "Yes" << endl;
}
  