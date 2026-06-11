#include <bits/stdc++.h>

using namespace std;

int main()
{

    for(;;){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> s(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> s.at(i);
            sum += s.at(i);
        }
        double m = (double)sum / (double)n;
        double a = 0.0;
        for(int i = 0; i < n; i++){
            double si = s.at(i);
            a += (si - m) * (si - m) / n;
        }
        printf("%.8f\n", sqrt(a));
    }

}
