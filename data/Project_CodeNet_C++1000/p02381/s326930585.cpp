#include<iostream>
using namespace std;
#include<iomanip>
#include<cmath>

int main()
{
    int i, n;
    double m, V;
    int s[1000];

    cout << fixed << setprecision(10) << endl;

    while(1){
        cin >> n;
        if(n == 0) break;

        m = 0, V = 0;

		for(i = 0; i < n; i++){ cin >> s[i];  m = m + s[i];}
        m = m / n;

        for(i = 0; i < n; i++){ V = V + (s[i] - m) * (s[i] - m);}
        cout << sqrt(V / n) << endl;
    }

    return 0;
}