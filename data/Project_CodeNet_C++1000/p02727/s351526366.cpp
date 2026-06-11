#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<long long> red(a);
    vector<long long> green(b);
    vector<long long> apple;

    for(long long i = 0; i < a; i++){
        cin >> red[i];
    }
    for(long long i = 0; i < b; i++){
        cin >> green[i];
    }
    for(long long i = 0; i < c; i++){
        long long clear;
        cin >> clear;
        apple.push_back(clear);
    }

    sort(red.begin(), red.end(), greater<long long>());
    sort(green.begin(), green.end(), greater<long long>());
   

    long long sum = 0;
    

    for(long long i = 0; i < x; i++){
        apple.push_back(red[i]);
    }
    for(long long i = 0; i < y; i++){
        apple.push_back(green[i]);
    }

    sort(apple.begin(), apple.end(), greater<long long>());

   for(long long i = 0; i < x+y; i++){
       sum += apple[i];
   }

    cout << sum << endl;
    return 0;
}