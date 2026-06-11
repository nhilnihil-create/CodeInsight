#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;


int main(){
    int S, W;
    cin >> S >> W;
    if (W >= S){
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
}