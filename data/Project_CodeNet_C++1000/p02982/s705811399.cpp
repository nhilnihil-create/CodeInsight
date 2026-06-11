#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
    using namespace std;
    
    int n, d;
    cin >> n >> d;
    auto x = vector<vector<int>>(n, vector<int>(d,0));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<d; j++)
            cin >> x[i][j];
    
    int c=0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            long int sum = 0;
            for(int k=0; k<d; k++){
                int t = x[j][k] - x[i][k];
                sum += t*t;
            }
            double dist = sqrt(sum);
            if(ceil(dist) == floor(dist)){
               c++;
            }
        }
    }
    cout << c << endl;

    return 0;
}
