#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std; 
int main() {
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector<int> x(n),y(n);
    int i;
    vector<int> far(n);
    int sum;
    double m1=0,m2=0,m3=0,mi=0;
    for ( i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for ( i = 0; i < n; i++)
    {
        cin >> y[i];
        far[i] = abs(x[i]-y[i]);
        m1 += far[i];
        m2 += far[i]*far[i];
        m3 += far[i]*far[i]*far[i];
    }
    m2 = sqrt(m2);
    m3 = cbrt(m3);
    mi = *max_element(far.begin(),far.end());
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    cout << mi << endl;


        
    return 0;
}
