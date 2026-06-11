#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double m;
    cin >> n >> m;
    int a[n];
    int i;
    double all=0;
    for (i = 0; i<n ; i++){
        cin >> a[i];
        all += a[i];
    }
    
    double bunki=all / 4.0 / m;
    sort(a, a+n, std::greater<>());
    for (i = 0; i<m; i++){
        if(a[i] < bunki){
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}