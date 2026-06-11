#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>>a(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    vector<double>distances;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            pair<int, int>city1 = a[i];
            pair<int, int>city2 = a[j];
            double d = pow(abs(city1.first - city2.first), 2) + pow(abs(city1.second - city2.second), 2);
            d = sqrt(d);
            distances.push_back(d);
            //cout << d << endl;
        }
    }
    
    double fact[10];
    fact[0] = 1;
    fact[1] = 1;
    for(int i= 2; i < 10; i++){
        fact[i] = i*fact[i-1];
        //cout << fact[i] << endl;
    }
    
    double total_distance = 0;
    for(auto d : distances){
        //cout << d << endl;
        //cout << fact[n-1] << endl;
        total_distance += 2*d*(double)fact[n-1];
    }
    total_distance/=fact[n];
    
    //cout << setprecision(12) << total_distance/fact[n] << endl;
    printf("%0.10lf\n", total_distance);
    
    
    
}
