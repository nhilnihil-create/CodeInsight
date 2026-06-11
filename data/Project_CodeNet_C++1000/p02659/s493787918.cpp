#include <bits/stdc++.h>

using namespace std;

#define lli  long long int
#define pb   push_back

int main(){
    double b;
    lli n, sum;
    cin >> n >> b;

    sum = round(b*100);
    sum = (n*sum)/100;
    cout << sum;
}