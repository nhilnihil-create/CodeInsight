#include <bits/stdc++.h>

using namespace std;

#define lli  long long int
#define pb   push_back

lli counter(lli div, lli n){
    lli counter=0;
    for(lli i=1; 1; i++){
        if(div*i <= n)counter = counter+(div*i);
        else break;
        //cout << counter << endl;
    }
    return counter;
}

int main(){
    lli n, sum=0;
    cin >> n;
    for(lli i=1; i<=n; i++){
        sum = sum + counter(i, n);
    }
    cout << sum;
}