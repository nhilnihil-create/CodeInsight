#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int a,b; cin >> a >> b;
    int count = 1, sum = a;
    while(sum < b){
        sum += (a-1);
        count++;
    }
    if(b == 1) 
    {
        cout << '0' << endl;
        return 0;
    }
    cout << count << endl;
    return 0;
}
