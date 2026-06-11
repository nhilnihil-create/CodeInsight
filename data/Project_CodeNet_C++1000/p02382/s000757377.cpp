#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main() {
    cout<<fixed<<setprecision(12);
    int n;
    double sum = 0, m = 0; 
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0;  i < n; i++) {
        cin >> x.at(i);
    }
    for (int i = 0;  i < n; i++) {
        cin >> y.at(i);
    }
    for(double p = 1; p < 4; p++) {
        for(int j = 0; j < n; j++) {
            sum += pow(fabs(x.at(j) - y.at(j)), p);
        }
        cout << pow(sum, 1.0/p) << endl;
        sum = 0;
    }
    for(int i = 0; i < n; i++) {
      if(abs(x.at(i) - y.at(i)) > m) {
        m = abs(x.at(i) - y.at(i));
      }
    }
  cout << m;
}
