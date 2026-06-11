#include <bits/stdc++.h>

using namespace std;

#define lli  long long int
#define pb   push_back

int main(){
    lli n, sum=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        if(i%3 == 0 || i%5 ==0 || i%15 == 0){
            continue;
        }
        sum = sum+i;
    }
    cout << sum;
}