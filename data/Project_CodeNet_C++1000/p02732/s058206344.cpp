#include <iostream>
#include <vector>
#include <map>
using namespace std;
using LL = long long int;
int main(){
    LL n;
    vector<LL> a;
    map<LL,LL> b;
    cin >> n;
    for(LL i = 0;i < n;i++){
        LL buf;
        cin >> buf;
        a.push_back(buf);
        b[buf]++;
    }
    LL counter = 0;
    for(LL i = 1;i <= n;i++){
        counter += (b[i] * (b[i] - 1))/2;

    }
    for(LL k = 0;k < n;k++){
        cout << counter  + 1 - b[a[k]] << endl;
    }
    return 0;
}
