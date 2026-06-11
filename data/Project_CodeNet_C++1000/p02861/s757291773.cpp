#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<double> x(n), y(n);
    for(int i=0; i<n; ++i){cin >> x[i] >> y[i];}
    vector<int> v(n); for(int i=0; i<n; ++i){v[i] = i;}
    
    double res = 0;
    do{
        double sum = 0;
        for(int i=0; i+1<n; ++i){
            int s = v[i], t = v[i+1];
            double isum = (x[s]-x[t])*(x[s]-x[t]);
            isum += (y[s]-y[t])*(y[s]-y[t]); 
          	isum = sqrt(isum);
          	sum += isum; //cout << isum << endl;
        } 
        
        res += sum;
    }while(next_permutation(v.begin(), v.end()));

    double k = 1;
    for(int i=1; i<=n; ++i){k *= i;}
    res /= k;
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}