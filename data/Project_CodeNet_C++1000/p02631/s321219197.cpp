#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n;
vector<ll> v(200100);
int main(){
    cin >> n;
    ll s=0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        s = s^v[i];
    }
    for(int i=0; i<n; i++){
        cout << (s^v[i]) << " ";
    }
    cout << "\n";
}