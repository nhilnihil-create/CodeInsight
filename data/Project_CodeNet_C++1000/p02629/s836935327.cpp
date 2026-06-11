#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
#define add push_back
 
using namespace std; 


int main() {

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;  t = 1; //cin >> t;
    while(t--){
        char arr[26];
        arr[0] = 'z';
        for(int i = 1; i < 26; i++)
            arr[i] = 'a' + i - 1;
        ll n; cin >> n;
        string str = "";
        while(n > 0){
            str = arr[n % 26] + str;
            if(n % 26 == 0) n-= 26;
            n /= 26;
        }     
        cout << str << endl;
    }
    return 0;
}