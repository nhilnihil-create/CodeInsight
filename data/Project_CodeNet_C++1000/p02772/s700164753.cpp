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
    int n;
    cin >> n;
    int a[110];
    int count = 0;
    int acount = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%2 == 0){
            count++;
            if(a[i]%3 == 0) acount++;
            else if(a[i]%5 == 0) acount++;
        }
    }
    
    if(count == acount) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
}
