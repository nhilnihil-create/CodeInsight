#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector <vector<int>> A(N, vector <int> (D));
    for (int i=0; i<N; i++){
        for (int j=0; j<D; j++){
            cin >> A.at(i).at(j);
        }
    }
    int count=0;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            int normal=0;
            for (int k=0; k<D; k++){
                int diff=abs(A[i][k]-A[j][k]);
                normal+=diff*diff;
            }
            bool integer=false;
            for (int k=0; k<=normal; k++){
                if (k*k==normal){
                    integer=true;
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}
