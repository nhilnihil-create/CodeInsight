#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define vi vector<int>
#define Sort(v) sort(v.begin(),v.end())

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;




int main(){
    int a,b;
    cin >> a >> b;
    
    double f = 1.000000*a/b;
    
    cout << fixed;
    cout << a/b <<" " << a%b <<" "<<setprecision(12) << f << endl;
    
    
}







