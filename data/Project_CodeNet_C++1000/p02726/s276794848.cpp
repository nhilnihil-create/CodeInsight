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
    int n,x,y;  cin >> n >> x >> y;
    vector<int>k(n);
    for(int i = 1; i < n; i++){
        k[i] = n-i;
    }
    /*
     * i <= x || y <= j
     */
    for(int i = 1; i <= x; i++){
        for(int j = y; j <= n; j++){
            k[j-i]--;
            k[j-i-(y-x-1)]++;
        }
    }
    /*
     * i <= x || x < j < y
     */
    for(int i = 1; i <= x; i++){
        for(int j = x+1; j < y; j++){
            if(y-j+1 < j-x){
                k[j-i]--;
                k[x-i+y-j+1]++;
            }
        }
    }
    /*
     * x < i < j < y
     */
    for(int i = x+1; i < y; i++){
        for(int j = i+1; j < y; j++){
            if(i >= j)  continue;
            if(i-x + y-j + 1 < j-i){
                k[j-i]--;
                k[i-x + y-j + 1]++;
            }
        }
    }
    /*
     * x < i < y || y <= j
     */
    for(int i = x+1; i < y; i++){
        for(int j = y; j <= n; j++){
            if(i-x+1 + j-y < j-i){
                k[j-i]--;
                k[i-x+1 + j-y]++;
            }
        }
    }
    for(int i = 1; i < n; i++){
        cout << k[i] << endl;
    }
}
