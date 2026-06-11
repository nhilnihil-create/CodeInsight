#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, m, sum=0, b, c=0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    b = (sum%(4*m) == 0) ? sum/(4*m) : sum/(4*m)+1;
    for(int i=0; i<n; i++){
        if(a[i] >= b) c++;
        if(c == m){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}