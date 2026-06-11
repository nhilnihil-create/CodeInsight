#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n,d;
    int cnt=0;

    cin >> n >> d;

    vector<vector<double>> x(n , vector<double>(d));

    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            cin >> x.at(i).at(j);
        }
    }

    double sum;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            sum = 0;
            for(int k=0; k<d; k++){
                sum += pow( x.at(i).at(k)-x.at(j).at(k) ,2);
            }

            bool flag = false;
            for(int k=1; k<= sum; k++){
                if(k * k == sum){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}