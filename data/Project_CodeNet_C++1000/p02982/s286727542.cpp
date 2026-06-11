#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
    int N,D,rs=0;
    double wa=0,ans=0;
    int digi=0;
    cin >> N >> D;

    vector<vector <int>> X(N,vector<int>(D));

    for(int i = 0;i < N;i++)
        for(int j = 0;j < D;j++){
            cin >> X.at(i).at(j);
        }

    for(int i = 0;i < N - 1;i++){
        for(int j = i + 1;j < N;j++){
            wa=0;
            for(int k = 0;k < D;k++){
                wa += (X.at(i).at(k) - X.at(j).at(k)) * (X.at(i).at(k) - X.at(j).at(k));
            }

            ans = sqrt(wa);

            digi = 0;
            while(digi < ans){
                digi++;
            }
            if((ans-digi) == 0)
                rs++;
        }
    }

    cout << rs << endl;

}