#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip>
#include <stack>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e14, cnt;


ll arr[100001];
int main(){
	ll n;
	cin>>n;
	queue<long long> q; 

    for (ll i = 1; i <= 9; i++) 
        q.push(i); 
    for (ll i = 1; i <= 100000; i++) { 
        arr[i] = q.front(); 
        q.pop(); 
        if (arr[i] % 10 != 0) 
            q.push(arr[i] * 10 + arr[i] % 10 - 1);
        q.push(arr[i] * 10 + arr[i] % 10); 
        if (arr[i] % 10 != 9) 
            q.push(arr[i] * 10 + arr[i] % 10 + 1); 

    }
    cout<<arr[n];
      

}